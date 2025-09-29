
r1 = int(input("Enter the number of rows: "))
c1 = int(input("Enter the number of columns: "))

m = [[0 for _ in range(c1)] for _ in range(r1)]

print("Enter the matrix:")

for i in range(r1):
    for j in range(c1):
        m[i][j] = int(input(f"Enter element at row {i+1}, col {j+1}: "))

print("\nOriginal Matrix:")

for row in m:
    print(row)


for j in range(2, c1, 3):  
    col = [m[i][j] for i in range(r1)] 
    col.reverse() 
    for i in range(r1):
        m[i][j] = col[i]  

print("\nMatrix with every 3rd column reversed:")

for row in m:
    print(row)
