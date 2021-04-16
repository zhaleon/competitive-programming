num = ['0' for _ in range(21)]

ans = 0

for i in range(1, 10 ** 6):
    k = 20
    while num[k] == '1':
        num[k] = '0'
        k -= 1
    num[k] = '1'

    s = ''.join(num) 
    while s[0] == '0':
        s = s[1:]
    if s == s[::-1] and str(i) == str(i)[::-1]:
        ans += i
        print(i, s)

print(ans)

    
