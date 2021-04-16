num = 600851475143

res = 0

n = int(num ** .5)

ind = dict()
primes = [];
is_prime = [True for _ in range(n+1)]

is_prime[0] = is_prime[1] = False

def sieve():
    cur_ind = 0
    for i in range(2,n+1):
        if (is_prime[i]):
            primes.append(i)
            ind[i] = cur_ind
            cur_ind += 1
            if (i**2 <= n):
                for j in range(i*i, n+1, i):
                    is_prime[j] = False
              
sieve()

for i in primes:
    if num % i == 0:
        res = max(res, i)
        
print(int(res))