l = list(map(int, input("Enter numbers separated by space: ").split()))
s = 0
n = len(l)

for i in range(0,n-1,1):
    for j in range(0,n-i-1,1):
        if l[j] > l[j+1]:
            temp = l[j]
            l[j] = l[j+1]
            l[j+1] = temp

print(l)
if n >= 2:
    print(l[n-2])
else:
    print("Second largest element not available")

for i in l:
    s += i

print(s)