str1 = 'madam1'
vowels = 'aeiou'
vc = 0
cc = 0
nc = 0
str2 = str1[::-1]

print(f"The reverse of {str1} is {str2}")

if str1 == str2:
    print("Palindrome")

for i in str1:
    if i in vowels:
        vc += 1
    elif i.isnumeric():
        nc += 1
    elif i.isalpha():
        cc += 1


print(vc,nc,cc)