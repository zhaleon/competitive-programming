n = 500 

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

target = 490 
comb = 0

def search(p, cur):
    global comb
    if (cur > target or p == 95):
        comb += 1    
        return
    
    while cur < target:
        search(p+1, cur)
        cur *= primes[p] 

search(0,1)

print(primes)

print(comb)
