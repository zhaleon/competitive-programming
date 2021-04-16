from itertools import permutations

ans = 0
primes = [2,3,5,7,11,13,17]
for perm in permutations(list(map(str, list(range(10))))):
    works = True
    for i in range(7):
        if int(''.join(perm[i+1:i+4])) % primes[i] != 0:
            works = False

    if works:
        ans += int(''.join(perm))

print(ans)
    


