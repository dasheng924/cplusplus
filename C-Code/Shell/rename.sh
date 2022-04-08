#! /bin/bash

echo "file_type----->"
echo ""
for filename in `ls` ;do
	if [ -d "$filename" ];then
		echo ""$filename" is a dir"
	elif [ -f "$filename" ];then
		echo ""$filename" is a f "
	else
		echo ""$filename"other"
	fi

done
		