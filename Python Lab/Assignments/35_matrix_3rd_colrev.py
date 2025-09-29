
r = int(input("Enter number of rows: "))
c = int(input("Enter number of columns: "))

m = []
print("Enter the matrix row by row:")
for i in range(r):
    row = list(map(int, input().split()))
    m.append(row)


for j in range(c):
    if (j + 1) % 3 == 0:  
        col = [m[i][j] for i in range(r)]
        col.reverse()
        for i in range(r):
            m[i][j] = col[i]

print("\nMatrix with every 3rd column reversed:")
for row in m:
    print(" ".join(map(str, row)))
