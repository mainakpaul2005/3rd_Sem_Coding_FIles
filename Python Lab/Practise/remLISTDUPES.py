l1 = [1,1,1,1,2,3,3,3,3,4,5,6,7]
res = []

for i in l1:
    if i not in res:
        res.append(i)

print(l1,"\n",res)

res = set(l1)
print(res)