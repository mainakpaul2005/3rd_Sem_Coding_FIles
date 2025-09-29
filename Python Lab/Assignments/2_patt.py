#*
#***
#*****
# upto n lines

n = int(input("Enter number of lines: "))

for i in range(1, n + 1):
    for j in range(0, i * (i + 1) // 2):
        print('*', end='')
    print()

