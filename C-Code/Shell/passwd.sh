#! /bin/bash
count=3
echo "enter your passwd?"
read PASSWD
while [ "$PASSWD" != "sec" -a $[count] -gt 0 ];do
	echo "Sorry,try again!"
	count=$[count]-1
	read PASSWD
done

if [ $[count] -eq 0 ];then
	echo "your 4 times is 0"
else
	echo "good luck!"
fi


return 0