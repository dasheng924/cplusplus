#! /bin/bash

i=100 
sum=0
while [ "$i" != 0 ];do#$i表示取i的值
	sum=$[sum+i]#算术转换  $[]   $(())
	i=$[i-1]

done 
echo "1-100的和为"$sum""