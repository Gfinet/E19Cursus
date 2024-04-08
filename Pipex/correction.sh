#!/bin/bash
# $# nb arg bash
#cmds= "cat" "ls" "grep" "wc" ""

#"${@: -1}" last one

#cmds="cat ls grep wc echo awk"

# IFS=' ' read -r -a arr <<< "$1"
flag=0
#echo "${arr[${#arr[@]}]- 1 }"

args=("$@")
# echo ${args[0]} 
# echo ${args[args[2]]}
# echo ${args[$#-2]}
# echo ${args[2]}
# echo $#

for (( i=0; i + 2<$#; i++ ))
do
	for (( j=0; j + 2<$#; j++ ))
	do
		echo "----- < ${args[$#-2]} ${args[i]} | ${args[j]} > b$((${@: -1}*i+j)) -----"
		< ${args[$#-2]} ${args[i]} | ${args[j]} > test/b$((${@: -1}*i+j))
	done
done

echo "Testing classic command"
for (( i=0; i + 2<$#; i++ ))
do
	for (( j=0; j + 2<$#; j++ ))
	do
		#echo "-----diff c$((${@: -1}*i + j)) b$((${@: -1}*i + j))-----"
		
		res=$(diff test/c$((${@: -1}*i + j)) test/b$((${@: -1}*i + j)))
		if [ $? -ne 0 ]
		then
    		# echo "files are the same"
		# else
			echo "Error \" < ${args[$#-2]} ${args[i]} | ${args[j]} > test/c$((${@: -1}*i + j)) test/b$((${@: -1}*i + j))\""
			flag=1
			# diff c$((4*i + j)) b$((4*i + j))
		fi	
	done
done

if [ $flag -ne 1 ]
then
	echo "Classice command OK"
fi

echo "Testing permissions command"
echo "Yolo" > test/no_perm_in_b > /dev/null 2>&1
echo "" > test/no_perm_out_b > /dev/null 2>&1
chmod 000 test/no_perm_in_b > /dev/null 2>&1
chmod 000 test/no_perm_out_b > /dev/null 2>&1
echo "----- < test/no_perm_in_b cat -e | wc -w > test/no_perm_out_b -----"
< test/no_perm_in_b cat -e | wc -w > test/no_perm_out_b > /dev/null 2>&1
chmod 777 test/no_perm_out_b > /dev/null 2>&1
chmod 777 test/no_perm_out_c > /dev/null 2>&1
res=$(diff test/no_perm_out_b test/no_perm_out_c)
if [ $? -ne 0 ]
then
	echo "Error \" < test/no_perm_out_b cat -e | wc -w > test/no_perm_out_b test/no_perm_out_c"
	flag=1
fi

echo "" > test/all_perm_out_b > /dev/null 2>&1
chmod 777 test/all_perm_out_b > /dev/null 2>&1
echo "----- < test/no_perm_in_b cat -e | wc -w > test/all_perm_out_b -----"
< test/no_perm_in_b cat -e | wc -w > test/all_perm_out_b > /dev/null 2>&1
res=$(diff test/all_perm_out_b test/all_perm_out_c)
if [ $? -ne 0 ]
then
	echo "Error \" < test/no_perm_in_b cat -e | wc -w > test/all_perm_out_b all_perm_out_c"
	flag=1
fi

echo "Yolo" > test/all_perm_in_b > /dev/null 2>&1
touch ./test/no_perm_out2_b > /dev/null 2>&1
chmod 000 test/no_perm_out2_b > /dev/null 2>&1
echo "----- < test/all_perm_in_b cat -e | wc -w > test/no_perm_out2_b -----"
< test/all_perm_in_b cat -e | wc -w > test/no_perm_out2_b > /dev/null 2>&1
chmod 777 test/no_perm_out2_c > /dev/null 2>&1
chmod 777 test/no_perm_out2_b > /dev/null 2>&1
res=$(diff test/no_perm_out2_b test/no_perm_out2_c)
if [ $? -ne 0 ]
then
	echo "Error \" < test/all_perm_in_b cat -e | wc -w > test/no_perm_out2_b test/no_perm_out2_c"
	flag=1
fi


if [ $flag -eq 0 ]
then
	echo "Everything is good"
else
	echo "Got some mistakes"
fi

echo "cleaning"
for (( i=0; i + 2<$#; i++ ))
do
	for (( j=0; j + 2<$#; j++ ))
	do
		#echo "-----rm c$((${@: -1}*i+j)) b$((${@: -1}*i+j))-----"
		rm test/c$((${@: -1}*i+j))
		rm test/b$((${@: -1}*i+j))
	done
done

chmod 777 test/all_perm_out_b
chmod 777 test/no_perm_in_b
chmod 777 test/no_perm_in_c
chmod 777 test/no_perm_out_b
chmod 777 test/no_perm_out2_b

rm ./test/no_perm_in_b
rm ./test/no_perm_out_b
rm ./test/no_perm_out2_b
rm ./test/all_perm_in_b
rm ./test/all_perm_out_b
rm ./test/no_perm_in_c
rm ./test/no_perm_out_c
rm ./test/no_perm_out2_c
rm ./test/all_perm_in_c
rm ./test/all_perm_out_c
rmdir test
echo "cleaning done"