#! /bin/bash

cd $1

for FILE in `ls`;do
	if [ "$FILE" = "*.c" ];then
		`gcc -o` "$FILE" "$FILE".out
	fi
done