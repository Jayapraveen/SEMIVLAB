echo "enter the number" 
read n 
rn=0 
sum=0 
while [ $n -gt 0 ] 
do 
d=`expr $n % 10` 
rn=`expr $rn \* 10 + $d` 
sum=`expr $sum + $d` 
n=`expr $n / 10` 
done 
echo "reverse of the digit is: $rn" 
echo "sum of the digit is: $sum" 
      
#OUTPUT
#enter the number 
#612 
#reverse of the digit is: 216 
#sum of the digit is: 9
