def tri(k):
    low, high = 1, 2 ** 30

    while low+1 < high:
        mid = (low + high)//2

        if mid * (mid+1) > 2*k:
            high = mid
        else:
            low = mid

    return low

def pen(k):
    low, high = 1, 2 ** 30

    while low+1 < high:
        mid = (low + high)//2

        if mid * (3*mid-1) > 2*k:
            high = mid
        else:
            low = mid

    return low

for j in range(144,10 ** 6):
    i = j * (2*j-1)
    t = tri(i)
    p = pen(i)

    if p * (3*p-1) // 2 == i and t * (t+1) // 2 == i:
        print(i)
        break
