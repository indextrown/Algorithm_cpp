li = [2, 1, 3, 4, 1]
li2 = []


for i in range(0, len(li)):
    for j in range(i+1, len(li)):
        li2.append(li[i]+j)
print(sorted(set(li2)))

