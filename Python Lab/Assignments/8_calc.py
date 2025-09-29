print("\tMenu\t")
print("\t----\t")
print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
print("5. Exit")

while(1):

    ch = int(input(("Press 1 to 5 to perform options: ")))

    if ch == 1:
        a = int(input("Enter the first number: "))
        b = int(input("Enter the second number: "))
        sum = a + b
        print("Result: ",sum)
    elif ch == 2:
        a = int(input("Enter the first number: "))
        b = int(input("Enter the second number: "))
        s = a - b
        print("Result: ",s)
    elif ch == 3:
        a = int(input("Enter the first number: "))
        b = int(input("Enter the second number: "))
        m = a * b
        print("Result: ",m)
    elif ch == 4:
        a = int(input("Enter the first number: "))
        b = int(input("Enter the second number: "))
        d = a / b
        print("Result: ",d)
    elif ch == 5:
        print("Thank You")
        break
    else:    
        print("\nInvalid Choice.\n")
        continue     


