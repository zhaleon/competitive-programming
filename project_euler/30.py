def possible(k):
    num = k
    while num > 0:
        k -= (num % 10) ** 5
        num //= 10
    
    return k == 0

ans = 0

for i in range(2,10**6):
    if possible(i):
        ans += i
        
print(ans)