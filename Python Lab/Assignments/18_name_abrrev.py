m = input("Enter your name: ")
c = ""

l = m.split()

print("Your Abbreviation: ", end="")

for j in l:
    c = c + j[0].upper() + "."

print(c)