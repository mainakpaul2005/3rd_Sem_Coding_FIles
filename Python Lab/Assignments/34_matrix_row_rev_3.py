


r1 = int(input("Enter the number of rows for the matrix: "))
c1 = int(input("Enter the number of columns for the matrix: "))

m = [[0 for _ in range(c1)] for _ in range(r1)]

print("Enter the matrix:")

for i in range(r1):
    for j in range(c1):
        m[i][j] = int(input(f"Enter element at row {i+1}, col {j+1}: "))

print("\nThe matrix is:")

for row in m:
    print(row)


print("\nMatrix with every 2nd row reversed:")

for i in range(r1):
    if (i + 1) % 2 == 0:   
        print(m[i][::-1])
    else:
        print(m[i])