#! /bin/bash

echo "Do you like me?"
read YES_OR_NO
case "$YES_OR_NO" in
yes|y|Yes|YES)
	echo "me too";;
[nN]*)
	echo "go go go!";;
*)
	echo "Sorry,I don't know!"
	return 1;;
esac
return 0


