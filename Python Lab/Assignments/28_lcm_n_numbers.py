n = int(input("Enter total numbers: "))

a = int(input("Enter number: "))

for j in range(n - 1):
    b = int(input("Enter number: "))
    hcf = 1
    for i in range(1, min(a, b) + 1):
        if a % i == 0 and b % i == 0:
            hcf = i
    a = (a * b) // hcf

print("LCM is", a)
