names = {
    1:'Mainak',
    2:'Sagnik',
    3:'Ankit'
}

print(names)

for i in names:
    print(names[i])

l3 = names.keys()

maxKEY = max(l3)

print("MAx key : ",maxKEY)

names[i+1] = 'Samata'

print(names)

print(names.popitem())

print(names.pop(3,None))

del names[2]

print(names)

a = ['apple', 'banana', 'apple', 'orange', 'banana', 'banana']

freq = {}
for item in a:
    freq[item] = freq.get(item, 0) + 1

print(freq)