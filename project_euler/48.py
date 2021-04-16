ans = 0

for i in range(1,1001):
    ans += pow(i,i,10 ** 10)

ans %= 10 ** 10

print(ans)
