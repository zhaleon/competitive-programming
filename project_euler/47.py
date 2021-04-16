d = [i for i in range(10 ** 6 + 1)]
is_prime = [True for i in range(10 ** 6 + 1)]
is_prime[0] = is_prime[1] = False

for i in range(2, 10 ** 6 + 1):
    if is_prime[i]:
        for j in range(i+i, 10**6+1, i):
            is_prime[j] = False
            d[j] = i

def has_four(k):
    factors = dict()
    
    while k > 1:
        if d[k] not in factors:
            factors[d[k]] = 1
        k = k // d[k]

    return len(factors) == 4


for i in range(10, 10 ** 6):
    ok = True
    for j in range(4):
        ok = ok and has_four(i+j)
    if ok:
        print(i)
        break
