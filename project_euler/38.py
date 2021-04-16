best = 0

for k in range(6):
    for i in range(100000):
        s = ""
        for j in range(1,k):
            s += str(i*j)

        if len(s) > 9:
            break
        s = list(map(str, list(dict.fromkeys(list(s)))))

        if '0' not in s and len(s) == 9:
            best = max(best, int(''.join(s)))

print(best)

