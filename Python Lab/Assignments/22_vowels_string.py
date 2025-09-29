a = "aeiou"

s = input("Enter a string: ")

c = 0

for i in s:
    for j in a:
        if i.lower() == j:
            c+=1

print("No of vowels: ",c)