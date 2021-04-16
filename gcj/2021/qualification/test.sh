set -e

# my sol, generator 
g++-10 -std=c++17 -O2 -Wl,-stack_size -Wl,0x80000000 $1 -o ${1%%.*}
g++-10 -std=c++17 -O2 -Wl,-stack_size -Wl,0x80000000 $2 -o ${2%%.*}

my_sol='./'${1%%.*}
gen='./'${2%%.*}
i=1
N=1
for ((; i <= $N; ++i)); do
    $gen > in.txt
    $my_sol < in.txt > out.txt 
    pypy3 ./checker.py
done




