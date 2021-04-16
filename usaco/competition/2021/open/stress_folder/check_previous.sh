#set -e

g++-10 -std=c++11 -O2 -Wl,-stack_size -Wl,0x80000000 $1 -o ${1%%.*}
g++-10 -std=c++11 -O2 -Wl,-stack_size -Wl,0x80000000 $2 -o ${2%%.*}

my_sol='./'${1%%.*}
brute='./'${2%%.*}

flag=0
num=1
for i in *.in; do
	[ -f "$i" ] || continue 
	
	$my_sol < $i > my_answer.txt
	$brute < $i > real_answer.txt

	diff -w my_answer.txt real_answer.txt > /dev/null 

	if [ $? -ne 0 ]
	then
		flag=1
		echo "WA on $num.in" 
		cat $i
		break
	fi
	((num++))
done

if [ $flag -ne 0 ]
then
	echo "My Answer:"
	cat my_answer.txt
	echo "Correct Answer:"
	cat real_answer.txt
else
	echo "Passed All Cases!"
fi
