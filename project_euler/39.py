best = 0
val = 0

for p in range(5,1001):
    score = 0
    for a in range(1,p-1):
        for b in range(a+1,p):
            if a*a + b*b == (p-b-a)**2:
                score += 1
    if score > best:
        best = score
        val = p

print(val, best)
