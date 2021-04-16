score = 0

real = open("real.txt", 'r')
my_ans = open("out.txt", 'r')

for line1, line2 in zip(real, my_ans):
    line1.replace(' ', '')
    line2.replace(' ', '')

    if line1 == line2:
        score += 1

print(f"{score}/50")

