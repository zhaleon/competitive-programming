import sys

names = []
total = 0
first = ord('A') - 1


for line in sys.stdin:
    line = line.replace('"', '')
    line = line.split(',')
    for s in line:
        names.append(s)

names.sort()

for i, name in enumerate(names):
    score = (i+1) * sum(ord(c)-first for c in name)
    total += score

print(total)    