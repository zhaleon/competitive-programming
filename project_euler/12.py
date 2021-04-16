def d(k):
    res = 0
    for i in range(1,int(k ** 0.5)):
        if k % i == 0:
            res += 2
        if i*i == k:
            res -= 1
    return res
    
num_divisors = 1
cur = 1
num = 1

while num_divisors <= 500:
    cur += 1
    num += cur
    num_divisors = d(num)

print(num)

