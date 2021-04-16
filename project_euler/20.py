def fact(k):
    if k == 1:
        return 1
    return k * fact(k-1)

n = 100
n = fact(n)

print(sum(int(c) for c in str(n)))

