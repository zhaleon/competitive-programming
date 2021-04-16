ans = 1
s = ""

i = 1
while (len(s) < 10**6+1):
    s += str(i)
    i += 1

for i in range(7):
    ans *= int(s[10**i-1])

print(ans)
