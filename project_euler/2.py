res = 2
a, b = 1, 2

while b < 4 * 10 ** 6:
    a, b = b, a+b
    if b % 2 == 0:
        res += b
        
print(res)