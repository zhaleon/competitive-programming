def d(k):
    res = 1
    i = 2
    while i*i <= k:
        if k % i == 0:
            res += i + k//i
            if i*i == k:
                res -= i
        i += 1
    return res

ans = 0

amt = dict()
sums = dict()

div = []

for i in range(1,10001):
    temp = [d(i), i]
    temp.sort()
    div.append(temp)
    
div.sort()

for i in range(len(div)-1):
    if div[i] == div[i+1]:
        ans += sum(div[i])

print(ans)