#!/bin/bash

#1) prends en arg infile cmd1 cmd2 numtest
#2) fais < infile cmd1 | cmd2 > b$numtest
#3) diff c$numtest b$numtest
#4) Si ok print ok, si error print error : < infile cmd1 | cmd2 > b$numtest
#5) clean

echo "testing : < $1 $2 | $3 > b$4"
< $1 $2 | $3 > b$4
echo "diff c$4 b$4"
res=$(diff c$4 b$4)
if [ $? -ne 0 ]
then
	echo "Error : \"$1 $2 | $3 > c$4 b$4\""
else
	echo "diff OK"
fi

rm c$4 b$4
