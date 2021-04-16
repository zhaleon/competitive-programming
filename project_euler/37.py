is_prime = [True for _ in range(10**6)]
is_prime[0], is_prime[1] = False, False 

primes = []

for i in range(2, 10**6):
    if is_prime[i]:
        primes.append(i)
        for j in range(i+i, 10**6,i):
            is_prime[j] = False

ans = 0

for prime in primes:
    if prime < 10:
        continue

    s = str(prime)

    ok = True
    for i in range(1,len(s)):
        ok = ok and is_prime[int(s[i:])]
        ok = ok and is_prime[int(s[:len(s)-i])]

    if ok:
        ans += prime
        print(prime)

print(ans)
