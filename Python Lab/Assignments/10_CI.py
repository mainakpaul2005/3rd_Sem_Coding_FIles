p = float(input("Enter the principal amount: "))
r = float(input("Enter the rate of interest: "))
t = float(input("Enter the time: "))
n = float(input("Enter the number of compoundings per year: "))


f = p * ((1 + (r / (100 * n))) ** (n * t))

c = f - p

print("Compound Interest: ", c)
