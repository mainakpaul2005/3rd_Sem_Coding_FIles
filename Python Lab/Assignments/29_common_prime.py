a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

print("Common Prime Factors are:", end=" ")

for i in range(2, min(a, b) + 1):
    
    if a % i == 0 and b % i == 0:
        
        p = True
        for j in range(2, i):
            if i % j == 0:
                p = False
                break
        if p:
            print(i, end=" ")
            continue