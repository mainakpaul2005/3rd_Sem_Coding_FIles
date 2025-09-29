def count(s):
    lc, uc = 0, 0
    for i in s:
        if i.islower():
            lc+=1
        if i.isupper():
            uc+=1
    return uc, lc

s = input("Enter a string: ")

u, l = count(s)
print("No of\nUppercase: ",u,"\nLowercase: ",l)
