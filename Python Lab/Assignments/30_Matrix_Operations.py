# Input sizes
r1 = int(input("Enter the number of rows for first matrix: "))
c1 = int(input("Enter the number of columns for first matrix: "))
r2 = int(input("Enter the number of rows for second matrix: "))
c2 = int(input("Enter the number of columns for second matrix: "))

# First matrix
m = [[0 for _ in range(c1)] for _ in range(r1)]
print("Enter the first matrix:")
for i in range(r1):
    for j in range(c1):
        m[i][j] = int(input(f"Enter element at row {i+1}, col {j+1}: "))

# Second matrix
n = [[0 for _ in range(c2)] for _ in range(r2)]
print("Enter the second matrix:")
for i in range(r2):
    for j in range(c2):
        n[i][j] = int(input(f"Enter element at row {i+1}, col {j+1}: "))

#Matrix Addition
if r1 == r2 and c1 == c2:
    res_add = [[0 for _ in range(c1)] for _ in range(r1)]
    for i in range(r1):
        for j in range(c1):
            res_add[i][j] = m[i][j] + n[i][j]
    print("Matrix Addition:")
    for row in res_add:
        print(row)
else:
    print("Addition not possible (matrices must be same size)")

#Matrix Multiplication
if c1 == r2:
    res_mul = [[0 for _ in range(c2)] for _ in range(r1)]
    for i in range(r1):
        for j in range(c2):
            for k in range(c1):
                res_mul[i][j] += m[i][k] * n[k][j]
    print("Matrix Multiplication:")
    for row in res_mul:
        print(row)
else:
    print("Multiplication not possible (columns of first != rows of second)")

#Matrix Inverse
if r1 == c1:  
    
    size = r1
    
    mat = [[float(m[i][j]) for j in range(size)] for i in range(size)]
    identity = [[1 if i == j else 0 for j in range(size)] for i in range(size)]

    possible = True
    for i in range(size):
        diag = mat[i][i]
        if diag == 0:
            possible = False
            break
        
        for j in range(size):
            mat[i][j] /= diag
            identity[i][j] /= diag
        
        for k in range(size):
            if k != i:
                factor = mat[k][i]
                for j in range(size):
                    mat[k][j] -= factor * mat[i][j]
                    identity[k][j] -= factor * identity[i][j]

    if possible:
        print("Inverse of First Matrix:")
        for row in identity:
            print(row)
    else:
        print("Inverse not possible (matrix is singular)")
else:
    print("Inverse not possible (first matrix not square)")
