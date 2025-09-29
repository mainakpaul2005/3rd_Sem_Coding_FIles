#1
#12
#123
#1234
#upto n lines

n = int(input("Enter the number of lines: "))

for i in range(1, n + 1): 
    for j in range(1, i + 1): 
        print(j, end=" ")
    print()
