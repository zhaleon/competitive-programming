a = 1
b = 1

idx = 2

while len(str(b)) < 1000:
    idx += 1
    b, a = b+a, b
    
print(b, idx)