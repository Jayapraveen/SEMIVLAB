/*
Algorithm:
1.  Create a new simulator instance.
2.  Set the color for data flows in NAM with blue and red color.
3.  Open the trace file and NAM file in write mode for both LS and DV.
4.  Create six nodes.
5.  Create duplex link between the nodes created and with proper orientation.
6.  Set up a TCP connection
7.  Then set up FTP over TCP.
8.  In the finish function, flush the trace file and execute the NAM file.
9.  The link from node 1 to node 4 is set to down at time 1.0 and up at time 4.5
10.Start ns and simulate till 5 minutes are over.
11. The comparison of LS and DV is displayed using xgraph tool.

CODING:
*/
//dv.tcl
set ns [new Simulator]
#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red
#Open the Trace file set file1 [open dv.tr w]
$ns trace-all $file1

#Open the NAM trace file set file2 [open dv.nam w]
$ns namtrace-all $file2

#Define a 'finish' procedure proc finish {} {
global ns file1 file2
$ns flush-trace close $file1 close $file2
exec nam dv.nam &
exit 0
}

# Next line should be commented out to have the static routing
$ns rtproto DV


#Create six nodes set n0 [$ns node] set n1 [$ns node] set n2 [$ns node] set n3 [$ns node] set n4 [$ns node] set n5 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n1 0.3Mb 10ms DropTail
$ns duplex-link $n1 $n2 0.3Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.3Mb 10ms DropTail
$ns duplex-link $n1 $n4 0.3Mb 10ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 10ms DropTail
$ns duplex-link $n4 $n5 0.5Mb 10ms DropTail

#Give node position (for NAM)
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient up

$ns duplex-link-op $n1 $n4 orient up-left
$ns duplex-link-op $n3 $n5 orient left-up
$ns duplex-link-op $n4 $n5 orient right-up

#Setup a TCP connection
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n5 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

#Setup a FTP over TCP connection set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns rtmodel-at 1.0 down $n1 $n4
$ns rtmodel-at 4.5 up $n1 $n4

$ns at 0.1 "$ftp start"
$ns at 6.0 "finish"
$ns run


/*Output:
[student@localhost ~]$ ns dv.tcl
[student@localhost ~]$ ns ls.tcl
[student@localhost ~]$ raw2xg -a ls.tr > ls.xg
 

[student@localhost~]$ raw2xg -adv.tr>dv.xg
[student@localhost~]$xgraphls.xgdv.xg -t“Comparisonof LS&DV”
 

Result:Thus the performance of Link State (LS) and Distance Vector (DV) routing protocol is compared and studied.
*/