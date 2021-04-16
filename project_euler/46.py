primes = []
is_prime = [True for _ in range(10 ** 6)]
is_prime[0], is_prime[1] = False, False

for i in range(2,10**6):
    if is_prime[i]:
        primes.append(i)
        for j in range(i+i, 10**6, i):
            is_prime[j] = False

for i in range(35, 10 ** 6,2):
    done = False
    if is_prime[i]:
        continue

    ok = False
    for j in range(1, 10 ** 6):
        k = j*j*2
        if k > i-1:
            break
        if is_prime[i-k]:
            ok = True
            break

    if not ok:
        print(i)
        break
