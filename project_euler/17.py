import os
import re
import subprocess

res = 0

for i in range(1,1001):
    cmd = "num2words " + str(i)
    s = subprocess.check_output(cmd, shell=True)
    s = str(s)
    s = s.strip()
    s = s.replace('-','')
    s = s.replace(' ','')
    res += len(s)-5
    print(s, len(s))

print(res)

res = 11 #one thou sand

length = dict()

length[1] = 3 #one
length[2] = 3 #two
length[3] = 5 #three
length[4] = 4 #four
length[5] = 4 #five
length[6] = 3 #six
length[7] = 5 #seven
length[8] = 5 #eight
length[9] = 4 #nine
length[10] = 3 #ten
length[11] = 6 #eleven
length[12] = 6 #twelve
length[13] = 8 #thirteen
length[14] = 8 #fourteen
length[15] = 7 #fifteen 
length[16] = 7 #sixteen
length[17] = 9 #seventeen
length[18] = 8 #eighteen
length[19] = 8 #nineteen
length[20] = 6 #twenty
length[30] = 6 #thirty
length[40] = 6 #fourty
length[50] = 5 #fifty
length[60] = 5 #sixty
length[70] = 7 #seventy
length[80] = 6 #eighty
length[90] = 6 #ninety
length[100] = 10 #one hundred

def get_len(k):
    res = 0
    
    if k == 0:
        return k
    elif k < 20:
        res += length[k]
    elif k <= 100: #sixty five
        if k % 10 == 0:
            return length[k]
            
        res += get_len(k % 10)
        k //= 10
        res += get_len(k * 10)
    else:
        if k % 100 == 0:
            res -= 3
            
        res += get_len(k % 100)
        k //= 100
        res += 10 + get_len(k)
    
    return res
        
        
for i in range(1,1000):
    res += get_len(i)
    
print(res)
print(get_len(400)) #four hundred and five


