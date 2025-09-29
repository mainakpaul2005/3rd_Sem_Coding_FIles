n = eval(input("Enter a List: "))
dupes = []

for i in range(len(n)):
    for j in range(i + 1, len(n)):
        if n[i] == n[j] and n[i] not in dupes:
            dupes.append(n[i])

print("Duplicates:", dupes)
