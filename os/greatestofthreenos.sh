echo "Enter three number" 
read a 
read b 
read c 
if [ $a -gt $b ] 
then 
if [ $a -gt $c ] 
then 
echo "$a is greater" 
else 
echo "$c is greater" 
fi 
else 
if [ $b -gt $c ] 
then 
echo "$b is greater" 
else 
echo "$c is greater" 
fi 
fi 

#OUTPUT
#Enter three numbers 
#5 
#1 
#9 
#9 is greater 
