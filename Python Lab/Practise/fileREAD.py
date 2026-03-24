file1 = open("hello.txt","r")

a = file1.readlines()

for i in a:
    print(i,end = "")

file1.close()