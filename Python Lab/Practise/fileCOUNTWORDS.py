file1 = open("hello.txt",'r')
c = 0
s = file1.readlines()

for i in s:
    c+=1

print("No of words:",c)