import sys

def convert(x):
    return ord(x)-ord('A')+1

def search(val):
    low, high = 0, 2 ** 20

    while low + 1 < high:
        mid = (low + high)//2

        if mid * (mid+1) // 2 > val:
            high = mid
        else:
            low = mid
    
    return low

ans = 0

for word in sys.stdin:
    word = word.replace(" ", "")
    word = word.split(',')
    for j in word:
        j = j[1:-1]
        val = sum(list(map(convert, j))) 

        num = search(val)
        if num * (num+1)//2 == val:
            ans += 1

print(ans)
