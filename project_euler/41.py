from itertools import permutations

def is_prime(s):
    if s % 2 == 0 or s % 3 == 0:
        return False
    for i in range(5,int(s**0.5+1)):
        if s % i == 0 or s % (i + 2) == 0:
            return False
    return True

for p in permutations(['1','2','3','4','5','6','7'][::-1]):
    s = int(''.join(p))
    if is_prime(s):
        print(s)
        break
