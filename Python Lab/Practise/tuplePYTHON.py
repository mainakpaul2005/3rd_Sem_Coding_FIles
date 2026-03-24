tup1 = (1,2,3,4,5,6,7,8)
tup2 = (9,10,1,2)
c = 0
for i in tup1:
    c += 1
print("No of elemensts: ",c)

max = tup1[0]

for i in tup1:
    if i > max:
        max = i

print("MAx = ",max)

min = tup1[0]

for i in tup1:
    if min > i:
        min = i

print("MIN: ",min)

l1 = list(tup1)

print(l1)
print(tuple(l1))

tup3 = tup1 + tup2

print(tup3)