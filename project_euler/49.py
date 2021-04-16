is_prime = [True for i in range(10 ** 6 + 1)]
is_prime[0] = is_prime[1] = False
primes = []

for i in range(2, 10 ** 6 + 1):
    if is_prime[i]:
        primes.append(i)
        for j in range(i+i, 10**6+1, i):
            is_prime[j] = False

for i in primes:
    if i < 1000:
        continue
    if is_prime[i+3330] and is_prime[i+3330*2]:
        if sorted(str(i+3330)) == sorted(str(i)) and sorted(str(i+6660)) == sorted(str(i)):
            print(str(i) + str(i+3330) + str(i+6660))

