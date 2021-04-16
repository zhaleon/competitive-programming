n = 1001
tot = 0

tot += sum((2*i+1) ** 2 for i in range(n//2 + 1)) 
tot += sum(2 * (2*i+1) ** 2 + 6*(i+1) for i in range(n//2))
tot += sum((2*i+1) ** 2 - 2* i for i in range(1, n//2 + 1))

print(tot)

