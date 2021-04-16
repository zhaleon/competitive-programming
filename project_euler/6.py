res = 0
big = 0

for i in range(1,101):
    res += i * i
    big += i
    
res = big ** 2 - res

print(res)
