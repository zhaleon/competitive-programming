for i in range(10 ** 6):
    nums = []
    for j in range(1,7):
        nums.append(sorted(str(i*j)))

    good = True
    for j in range(5):
        if nums[j] != nums[j+1]:
            good = False

    if good:
        print(i)
