def d(k):
    res = 1
    i = 2
    while i*i <= k:
        if k % i == 0:
            res += i + k // i
        if i*i == k:
            res -= i
        i += 1
    
    return res

possible = [False for _ in range(28124)]
abundant = []

for i in range(1, 28124):
    if d(i) > i:
        abundant.append(i)
        
for i in abundant:
    for j in abundant:
        if i + j <= 28123:
            possible[i + j] = True
            

tot = 0

for i in range(28124):
    if not possible[i]:
        tot += i
        
print(tot)
