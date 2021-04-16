longest = 0
best = 0

for i in range(1, 10 ** 6 + 1):
    reps = 1
    k = i
    while i != 1:
        reps += 1
        if i % 2 == 0:
            i //= 2
        else:
            i *= 3
            i += 1
    
    if reps > longest:
        longest = reps
        best = k
    
print(best)