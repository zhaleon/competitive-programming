import sys

grid = []

for line in sys.stdin:
    grid.append(list(map(int, line.split())))
    
best = 0

for i in range(16):
    for j in range(20):
        cur = 1
        for k in range(i,i+4):
            cur *= grid[k][j]
        best = max(cur, best)
        
for i in range(20):
    for j in range(16):
        cur = 1
        for k in range(j,j+4):
            cur *= grid[i][k]
        best = max(cur, best)
        
for i in range(16):
    for j in range(16):
        cur = 1
        cur2 = 1
        for k in range(4):
            cur *= grid[i+k][j+k]
            
        for k in range(4):
            cur2 *= grid[i+k][19-j-k]
        best = max(cur, best, cur2)
        
print(best)