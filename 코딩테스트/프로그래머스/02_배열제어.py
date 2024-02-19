li = [2,1,1,3,2,5,4]

def solutcion(li):
    new_li = sorted(set(li), reverse=True)
    return new_li

print(li)
print(solutcion(li))