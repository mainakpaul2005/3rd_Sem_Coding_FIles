print("\tMenu\t")
print("\t----\t")
print("1. Kg to Pound :")
print("2. Pound to Kg :")
print("3. Exit :")

while(1):

    ch = int(input("Enter 1 to 3 to perform operations: "))
    
    if ch == 1:
        kg = float(input("Enter Weight in Kg: "))
        p = (float) (2.2046 * kg)
        print("Weight in Pounds: ",p)

    elif ch == 2:
        p = float(input("Enter Weight in Pounds: "))
        kg = (float) (p/2.2046)
        print("Weight in Kg: ",kg)

    elif ch == 3:
        print("Thank You.")
        break

    else:
        print("Invalid Choice.")
        continue
