#! /bin/bash

cd $1
for NAME in `ls`;do
	base=${NAME%.*}
	mv $NAME ${base}.bak
done

#for i in *.*; do
#mv $i ${i%%.*}.bak
#done