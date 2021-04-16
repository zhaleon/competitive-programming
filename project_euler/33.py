from math import gcd

num = 1
den = 1
count = 1
for i in range(10,100):
    for j in range(i+1,100):
        if i % 10 == 0 and j % 10 == 0:
            continue
        a,b = str(i), str(j)
        for kk in range(10):
            k = str(kk)
            if k in a and k in b:
                c,d = a.replace(k,"",1), b.replace(k,"",1)
                if b == '0' or d == '0':
                    continue
                if (abs(float(a)/float(b) - float(c)/float(d)) < 1e-13):
                    num *= int(c) // gcd(int(c), int(d))
                    den *= int(d) // gcd(int(c), int(d))
                    count += 1
                    print(a,b,c,d, count)

den /= gcd(num, den)
print(den)
