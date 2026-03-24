n = int(input("Enter a number: "))
c = 0
if n < 2:
    print("Not PRIME")
else:
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            c += 1
            break

    if c > 0:
        print("Not PRIME")
    else:
        print("PRIME")