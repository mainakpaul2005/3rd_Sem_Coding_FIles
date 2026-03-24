file1 = open("hello.txt","a")

file1.write("\nMKC")

s2 = [' hello',' i am',' mainak!']

file1.writelines(s2)

file1.close()