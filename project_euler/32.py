used = dict()
ans = 0

for i in range(5000):
    for j in range(i+1,5000):
        s = str(i) + str(j) + str(i*j)
        if len(list(dict.fromkeys(s))) == len(s) and i*j not in used and '0' not in s and len(s) == 9:
            print(i,j,i*j)
            used[i * j] = 1
            ans += i*j

print(ans)
