l = eval(input("Enter a list of nos: "))

c = 0

if(len(l) < 3):
    print("Error not a list with more than 3 nos.")
else:
    for i in range(len(l)-1):
        if l[i] % 2 != 0:
            c+=1
        if c == 3:
            print("The popped integer: ",l[i])
            c = 0



   


