from math import sqrt

eps = 1e-15
    
for i in range(1,1000):
    for j in range(i+1,1000):
        k = sqrt(j*j-i*i)
        a = int(k)
        if k-a <= eps and a + i + j == 1000:
            print(a*i*j,k,a)