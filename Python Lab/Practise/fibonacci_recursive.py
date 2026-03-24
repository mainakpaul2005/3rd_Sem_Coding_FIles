n = int(input("Enter number of terms: "))


def fib(term):
    if term <= 1:
        return term
    return fib(term - 1) + fib(term - 2)


if n <= 0:
    print("Please enter a positive integer.")
else:
    print("Fibonacci series (recursive):")
    for i in range(n):
        print(fib(i), end=" ")
