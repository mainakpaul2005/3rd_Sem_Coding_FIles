print("\tMenu\t")
print("\t----\t")
print("1. C to F")
print("2. F to C")
print("3. Exit")

while(1):

    ch = int(input(("Press 1 to 3 to perform options: ")))

    if ch == 1:
        c = float(input("Enter the temperature in C: "))
        res = (float) (((9/5)*c)+32)
        print("Temperature in F: ",res)
    elif ch == 2:
        f = float(input("Enter the temperature in F: "))
        res = float( (5/9)*(f - 32))
        print("Temperature in C: ",res)
    elif ch == 3:
        print("Thank You")
        break
    else:    
        print("Invalid Choice \n")      
        continue


