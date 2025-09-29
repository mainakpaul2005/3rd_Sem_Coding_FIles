print("\tMenu\t")
print("\t----\t")
print("1. cm to inch :")
print("2. Inch to cm :")
print("3. Exit :")

while(1):

    ch = int(input("Enter 1 to 3 to perform operations: "))
    
    if ch == 1:
        c = float(input("Enter length in cm: "))
        i = (float) (0.394 * c)
        print("length in inch: ",i)

    elif ch == 2:
        i = float(input("Enter length in inch: "))
        c = (float) (i/0.394)
        print("length in cm: ",c)

    elif ch == 3:
        print("Thank You.")
        break

    else:
        print("Invalid Choice.")
        continue
