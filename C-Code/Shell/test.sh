#! /bin/bash

echo "Do you like me ?Please enter yes or no."
read RET
if [ "$RET" = "yes" ];then
	echo "me too!"
elif [ "$RET" = "no" ];then
	echo "go go go!!!"
else
	echo "you enter err!"
	return 1
fi
return 0
