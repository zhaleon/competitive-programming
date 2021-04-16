nums = dict()

for a in range(2,101):
    for b in range(2,101):
        if pow(a,b) not in nums:
            nums[pow(a,b)] = 1

print(len(nums.items()))