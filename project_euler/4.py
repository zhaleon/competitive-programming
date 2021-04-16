res = 0

for i in range(1,1000):
    for j in range(1,1000):
        s = str(i*j)
        if s == s[::-1]:
            res = max(res, int(s))
            
print(res)