#!/bin/bash
# $# nb arg bash
#cmds= "cat" "ls" "grep" "wc" ""

#"${@: -1}" last one

#cmds="cat ls grep wc echo awk"

# IFS=' ' read -r -a arr <<< "$1"
flag=0
#echo "${arr[${#arr[@]}]- 1 }"

args=("$@")
#echo ${args[0]} ${args[1]} ${args[2]}

for (( i=0; i + 1<$#; i++ ))
do
	for (( j=0; j + 1<$#; j++ ))
	do
		echo "-----< infile ${args[i]} | ${args[j]} > b$((${@: -1}*i+j)) -----"
		< infile ${args[i]} | ${args[j]} > test/b$((${@: -1}*i+j))
	done
done

echo "Testing..."
for (( i=0; i + 1<$#; i++ ))
do
	for (( j=0; j + 1<$#; j++ ))
	do
		#echo "-----diff c$((${@: -1}*i + j)) b$((${@: -1}*i + j))-----"
		
		res=$(diff test/c$((${@: -1}*i + j)) test/b$((${@: -1}*i + j)))
		if [ $? -ne 0 ]
		then
    		# echo "files are the same"
		# else
			echo "Error \"< infile ${args[i]} | ${args[j]} > test/c$((${@: -1}*i + j)) test/b$((${@: -1}*i + j))\""
			flag=1
			# diff c$((4*i + j)) b$((4*i + j))
		fi	
	done
done

if [ $flag -eq 0 ]
then
	echo "Everything is good"
else
	echo "Got some mistakes"
fi

echo "cleaning"
for (( i=0; i + 1<$#; i++ ))
do
	for (( j=0; j + 1<$#; j++ ))
	do
		#echo "-----rm c$((${@: -1}*i+j)) b$((${@: -1}*i+j))-----"
		rm test/c$((${@: -1}*i+j))
		rm test/b$((${@: -1}*i+j))
	done
done
rmdir test
echo "cleaning done"