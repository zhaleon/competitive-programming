best = 0

for i in range(1,100):
    res = i
    for j in range(1,100):
        res *= i
        best = max(best, sum(list(map(int, list(str(res))))))

print(best)
