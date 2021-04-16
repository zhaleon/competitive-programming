n = int(1e6+1)
isPrime = [1]*(n)

primes = []

isPrime[0] = isPrime[1] = 0;

for i in range(2,n):
	if isPrime[i] and i*i <= n-1:
		for j in range (i*i,n,i):
			isPrime[j] = 0

for i in range(n):
	if isPrime[i]:
		primes.append(i)
		
most = 0
ans = 0
for i in range(n):
	if primes[i] > n//2:
		break
	sum = 0
	for j in range(i,n):
		sum += primes[j] 
		if sum > n-1:
			break
		if isPrime[sum] and j-i+1 > most:
			ans = sum
			most = j-i+1

print(ans)
