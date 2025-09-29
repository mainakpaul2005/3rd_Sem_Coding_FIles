
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


row_f = False

for i in range(r):
    for j in range(i + 1, r):
        if m[i] == m[j]:
            print(f"\nIdentical Rows: Row {i+1} and Row {j+1}")
            print("Row", i+1, ":", m[i])
            print("Row", j+1, ":", m[j])
            row_f = True


col_f = False

for i in range(c):
    for j in range(i + 1, c):
        identical = True
        for k in range(r):
            if m[k][i] != m[k][j]:
                identical = False
                break
        if identical:
            print(f"\nIdentical Columns: Column {i+1} and Column {j+1}")
            print("Column", i+1, ":", [m[k][i] for k in range(r)])
            print("Column", j+1, ":", [m[k][j] for k in range(r)])
            col_f = True

if not row_f and not col_f:
    print("\nNo identical rows or columns found.")
