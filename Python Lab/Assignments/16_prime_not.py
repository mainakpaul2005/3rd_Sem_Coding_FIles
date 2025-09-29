n = int(input("Enter a number: "))

l = (int) (n ** 0.5)
 
c = 0

for i in range(2,l):
    if n % i == 0:
        c += 1

if c != 0:
    print(n,"is not a prime number.")
else:
    print(n,"is a Prime number.")