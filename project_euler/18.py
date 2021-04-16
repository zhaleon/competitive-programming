import sys

nums = [0]

for line in sys.stdin:
    temp = list(map(int, line.split()))
    for i in temp:
        nums.append(i)

ans = 0

def get_row(k):
    row = 1
    while row * (row + 1) < k*2:
        row += 1
    return row


def search(k):
    if k > 105:
        return nums[k]
    
    row = get_row(k)
    
    return nums[k] + max(search(k + row), search(k + row + 1))
    
print(search(1))