#!/bin/bash

#cmds="cat ls grep wc echo awk"

IFS=' ' read -r -a arr <<< "$1"

for (( i=0; i<${#arr[@]}; i++ ))
do
	for (( j=0; j<${#arr[@]}; j++ ))
	do
		# echo "-----${arr[i]} infile | ${arr[j]} > b$((4*i+j)) -----"
		${arr[i]} infile | ${arr[j]} > b$((4*i+j))
	done
done


for (( i=0; i<${#arr[@]}; i++ ))
do
	for (( j=0; j<${#arr[@]}; j++ ))
	do
		# echo "-----diff c$((4*i + j)) b$((4*i + j))-----"
		
		res=$(diff c$((4*i + j)) b$((4*i + j)))
		if [ $? -ne 0 ]
		then
    		# echo "files are the same"
		# else
			echo "Error \"${arr[i]} infile | ${arr[j]} > c$((4*i + j)) b$((4*i + j))\""
			# diff c$((4*i + j)) b$((4*i + j))
		fi	
	done
done

echo "cleaning"
for (( i=0; i<${#arr[@]}; i++ ))
do
	for (( j=0; j<${#arr[@]}; j++ ))
	do
		#echo "-----rm c$((4*i+j)) b$((4*i+j))-----"
		rm c$((4*i+j))
		rm b$((4*i+j))
	done
done
echo "cleaning done"
