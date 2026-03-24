n = int(input("Enter number of terms: "))

if n <= 0:
    print("Please enter a positive integer.")
else:
    first = 0
    second = 1
    print("Fibonacci series (loop):")

    for _ in range(n):
        print(first, end=" ")
        next_term = first + second
        first = second
        second = next_term
