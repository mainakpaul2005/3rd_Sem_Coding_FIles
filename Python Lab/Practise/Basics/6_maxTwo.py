num1 = int(input("Enter 1st Number: "))
num2 = int(input("Enter 2nd Number: "))

if num1 > num2:
    print(f"{num1} is Max.")
elif num1 < num2:
    print(f"{num2} is Max.")
else:
    print(f"{num1} and {num2} are equal.")