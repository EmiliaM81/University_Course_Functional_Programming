def reduce(a):
    
    if (type(a) == int or type(a) == float):
      return a

    if type(a)== tuple and len(a) == 3: 
        if a[1] == '+':
            return reduce(a[0])+reduce(a[2])
        elif a[1] == '-':
            return reduce(a[0])-reduce(a[2])
        elif a[1] == '*':
            return reduce(a[0])*reduce(a[2])
        elif a[1] == '/':
            if a[2] != 0:
                return reduce(a[0])/reduce(a[2])
            else:
                return -1
    else:
        return -1

    

e = ((1,'+', 6), '*', (2,'+', 7))

f = ((1,'+', 6), '*',( 2, '*' ,(2,'+', 7)))


print("wynik", reduce(e))
print("wynik", reduce(f))
