a = int(input("Enter a number: "))
b = int(input("Enter another number: "))
c = int(input("Enter another number: "))

if a >= b and a >= c:
	largest = a
elif b >= a and b >= c:
	largest = b
else:
	largest = c

print("Maximum number is:", largest)
