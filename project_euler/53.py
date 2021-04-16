def choose(n,k):
    res = 1
    for i in range(n,n-k,-1):
        res *= i
    for i in range(1,k+1):
        res //= i
    return res

ans = 0

for i in range(1,101):
    for j in range(i+1):
        if choose(i,j) > 10 ** 6:
            ans += 1

print(ans)
