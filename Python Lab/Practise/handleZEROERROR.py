a = int(input("Enter num1: "))
b = int(input("Enter num2: "))

try:
    res = a/b
except ZeroDivisionError:
    res = "undefined"

print("Result: ",res)

