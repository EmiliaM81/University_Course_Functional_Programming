import math

def check_arg(warunek, val):
    def inn1(fun):
        def inn2(arg):
            if warunek(arg):
                return fun(arg)
            else:
                return val
        return inn2
    return inn1


@check_arg(lambda x: x>0, 0)
def s(x):
    return math.sqrt(x)

print(s(4))

print(s(-100))