def max_three(a,b,c):
    return max(a,b,c)
    
a, b, c = map(int, input("Enter First, Second and Third No. : ").split())

print("Maximum of Three Nos: ",max(a,b,c))