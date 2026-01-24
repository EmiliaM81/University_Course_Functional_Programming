def for_list(fun):
    def for_every(x):
        if not x:
            return[]
        return [fun(x[0])] + for_every(x[1:])
    return for_every

def x2(x): return (x+2)*x




def for_list1(fun):
    return lambda lst: list(map(fun, lst))

lx2 = for_list1(x2)
d = [2,4,5,0.56]

r = lx2(d)

print(r)
