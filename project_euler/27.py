n = 10 ** 5 + 1
primes = [];
is_prime = [True for _ in range(n+1)]

is_prime[0] = is_prime[1] = False

def sieve():
    for i in range(2,n+1):
        if (is_prime[i]):
            primes.append(i)
            if (i**2 <= n):
                for j in range(i*i, n+1, i):
                    is_prime[j] = False

sieve()

best = 0
ans = 0

for i in range(-1000,1000):
    for j in range(-1000,1000):
        n = 0
        while is_prime[n*n + i*n + j]:
            n += 1
            
        if n > best:
            best, ans = n, i*j
            
print(ans)
