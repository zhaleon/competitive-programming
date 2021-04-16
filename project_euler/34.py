fact = [i for i in range(10)]

fact[0] = 1
for i in range(1,10):
    fact[i] = fact[i-1] * i

ans = 0

for i in range(3, 10 ** 7):
    s = list(map(int, list(str(i))))
    j = i
    for k in s:
        j -= fact[k]
    if j == 0:
        ans += i
        print(i)

    
print(fact)
print(ans)
