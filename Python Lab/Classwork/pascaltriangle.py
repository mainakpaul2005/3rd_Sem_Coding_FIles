n = int(input("Enter the number of rows: "))

for i in range(n):
    for s in range(n - i):
        print("  ", end="")
    coef = 1
    for j in range(i + 1):
        if j == 0 or i == 0:
            coef = 1
        else:
            coef = coef * (i - j + 1) // j
        print(f"{coef:4}", end="")
    print()
