def repeats(d):
    last = dict()
    num = 1
    ind = 1
    last[0] = 0
    
    while num not in last:
        last[num] = ind  
        
        while num < d:
            num *= 10

        num %= d
        ind += 1
    
    if num == 0:
        return 0
    else:
        return ind - last[num]

best = 0
ind = 0

for i in range(2,1001):
    if repeats(i) > best:
        best, ind = repeats(i), i

print(ind)