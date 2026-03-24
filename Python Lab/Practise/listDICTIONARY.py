l1 = [1,2,3]
l2 = ['mainak','sagnik','ankit']

n1 = len(l1)
n2 = len(l2)

dict1 = {}

if n1 < n2:
    n = n1
else:
    n = n2

for i in range(0,n,1):
    dict1[l1[i]] = l2[i]

print(dict1)