#! /bin/bash

#cd $1
#for NAME in `ls`;do
#	base=${NAME%.*}
#	mv $NAME ${base}.bak
#done
cd $1
for i in *.*; do
	if [ "$i"="hello.bak" ];then
		mv $i hello
	else
    	mv $i ${i%%.*}.c
	fi
done