P = [i * (3*i-1) // 2 for i in range(1,10 ** 4 + 1)]

good = dict()

for p in P:
    good[p] = 1

ans = 2 ** 31

for i in range(10 ** 4):
    for j in range(i+1, 10**4):
        if P[i]+P[j] in good and abs(P[j]-P[i]) in good:
            ans = min(ans, abs(P[i]-P[j]))

print(ans)
