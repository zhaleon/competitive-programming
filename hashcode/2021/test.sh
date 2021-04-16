g++ -std=c++17 -O3 -o sol sol.cpp

for i in A B C D E F; do
	echo $i
	./sol < $i.txt > $i.output
	# ./score < $i.out
done
wait
