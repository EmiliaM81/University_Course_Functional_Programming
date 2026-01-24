a = ["hello", "0", "to 2 centy", "x", "but o nr 44", "3 wilgi"]



from functools import reduce

y = list(enumerate(a))

#print(y)



def findInWord(l):
    return list(filter(lambda x: str(x[0]) in x[1], l))


result = findInWord(y)

result = list(map(lambda x: x[1], result))




print(result)