r = int(input("Enter the number of rows for the Array: "))
c = int(input("Enter the number of columns for the Array: "))

m = [[0 for _ in range(c)] for _ in range(r)]

print("Enter the Array:")

for i in range(r):
    for j in range(c):
        m[i][j] = int(input(f"Enter element at row {i+1}, col {j+1}: "))

print("\nThe Array is:")
for row in m:
    print(row)


row_flag = False
for i in range(r // 2):
    if m[i] == m[r - 1 - i][::-1]: 
        print(f"\nRow {i+1} and Row {r - i} are reverse of each other")
        print("Row", i+1, ":", m[i])
        print("Row", r - i, ":", m[r - 1 - i])
        row_flag = True


col_flag = False
for j in range(c // 2):
    col1 = [m[x][j] for x in range(r)]
    col2 = [m[x][c - 1 - j] for x in range(r)]
    if col1 == col2[::-1]: 
        print(f"\nColumn {j+1} and Column {c - j} are reverse of each other")
        print("Column", j+1, ":", col1)
        print("Column", c - j, ":", col2)
        col_flag = True

if not row_flag and not col_flag:
    print("\nNo complimentary rows or columns are reverse of each other.")
