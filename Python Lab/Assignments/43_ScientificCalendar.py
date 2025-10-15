import math

a, b = (float(i) for i in input("Enter two numbers (a b): ").split())

print("Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Square Root\n7. Logarithm\n8. Sin\n9. Cos\n10. Tan\n11. e to the power x\n12. Exit")
choice = int(input("Enter your choice (1-12): "))

while(1):
    print("Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Square Root\n7. Logarithm\n8. Sin\n9. Cos\n10. Tan\n11. e to the power x\n12. Exit")
    choice = int(input("Enter your choice (1-12): "))
    if choice == 1:
        result = a + b
        print("Result:", result)
    elif choice == 2:
        result = a - b
        print("Result:", result)
    elif choice == 3:
        result = a * b
        print("Result:", result)
    elif choice == 4:
        if b != 0:
            result = a / b
            print("Result:", result)
        else:
            print("Error: Division by zero")
    elif choice == 5:
        result = a ** b
        print("Result:", result)
    elif choice == 6:
        if a >= 0:
            result = math.sqrt(a)
            print("Square root of", a, "is", result)
        else:
            print("Error: Cannot compute square root of a negative number")
    elif choice == 7:
        if a > 0:
            result = math.log(a)
            print("Natural logarithm of", a, "is", result)
        else:
            print("Error: Logarithm undefined for non-positive numbers")
    elif choice == 8:
        result = math.sin(a)
        print("Sine of", a, "is", result)
    elif choice == 9:
        result = math.cos(a)
        print("Cosine of", a, "is", result)
    elif choice == 10:
        result = math.tan(a)
        print("Tangent of", a, "is", result)
    elif choice == 11:
        result = math.exp(a)
        print("e to the power of", a, "is", result)
    elif choice == 12:
        break

print("Exiting the program.")