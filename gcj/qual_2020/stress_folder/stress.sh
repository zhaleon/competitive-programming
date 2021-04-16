set -e

# generator, brute force, real, checker

g++-10 -std=c++11 -O2 -Wl,-stack_size -Wl,0x80000000 $1 -o ${1%%.*}
g++-10 -std=c++11 -O2 -Wl,-stack_size -Wl,0x80000000 $2 -o ${2%%.*}
g++-10 -std=c++11 -O2 -Wl,-stack_size -Wl,0x80000000 $3 -o ${3%%.*}

my_sol='./'${2%%.*}
brute='./'${3%%.*}

i=1
n=1000
for ((; i <= $n; i++)); do
	./gen $i > in.txt

	$brute < in.txt > real_answer.txt
	$my_sol < in.txt > my_answer.txt

	#just assume tests work??? and exclude this
	if [ $? -ne 0 ] 
	then
		echo RTE My Solution
		break
	fi

	diff -w my_answer.txt real_answer.txt > /dev/null || break
done

if (($i > $n)); then
	echo Passed All Cases!
else
	echo "WA case #$i:"
	cat in.txt
	echo "My answer:"
	cat my_answer.txt
	echo "Correct answer:"
	cat real_answer.txt
fi
