def next_permutation(nums):
    if nums[1:] == sorted(nums[1:])[::-1]:
        big = 10 ** 6
        idx = 0
        for i in range(len(nums[1:])):
            if nums[1+i] < big and nums[1+i] > nums[0]:
                idx = 1+i
                big = nums[1+i]
        
        nums[0], nums[idx] = nums[idx], nums[0]
        nums = [nums[0]] + sorted(nums[1:])
        return nums
        
    return [nums[0]] + next_permutation(nums[1:])
    
my_list = list(range(10))

for i in range(10**6-1):
    my_list = next_permutation(my_list)


my_list = ''.join(str(c) for c in my_list)
print(my_list)