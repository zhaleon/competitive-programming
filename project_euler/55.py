ans = 0

for i in range(1,10000):
    k = str(i)
    for j in range(50):
        k = str(int(k) + int(k[::-1]))
        if k == k[::-1]:
            break
    else:
        ans += 1

print(ans)
