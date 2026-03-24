def message(n):
    if n == 1:
        print("TMKC")
    else:
        print("HELLO !!")

def add(a,b):
    s = a + b
    return s

def oddeven(n):
    if n % 2 == 0:
        return 0
    else:
        return -1
    
n = 2
a = 2
b =3

message(n)

print(add(a,b))

if oddeven(n) == 0:
    print("EVEN")
else:
    print("ODD")