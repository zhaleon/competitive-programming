import sys

res = 0

for line in sys.stdin:
    res += int(line)
    
while len(str(res)) > 10:
    res //= 10
    
print(res)
