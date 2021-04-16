is_prime = [True for _ in range(10 ** 6)]

is_prime[0] = False
is_prime[1] = False

primes = []

for i in range(2,10 ** 6):
    if is_prime[i]:
        primes.append(i)
        for j in range(i+i, 10 ** 6, i):
            is_prime[j] = False

ans = 0

for j in primes:
    k = str(j)
    k = k[-1] + k[:-1]

    ok = True
    for i in range(len(k)-1): 
        ok = ok and is_prime[int(k)]
        k = k[-1] + k[:-1]

    if ok:
        ans += 1

print(ans)
