set_size=100
num_sets=100

for ((set = 1; $set <= $num_sets; ++set)); do
    time( 
    for ((i = 1; $i <= $set_size; ++i)); do
        (($i < set_size))
    done)
    echo "Passed Case #$(($set_size * $set))"
done
