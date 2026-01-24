x=7
y=3
z=x+y

print(x,y,z)

# python3 w1.py

#python3 -i w1.py

# z *2
# exit()

#dir() - jakie zmienne sa dostepne

#type(z) - jaki typ zmiennej

#dir(i) - lista dostepnych metod

#help(str)

#i.TAB - wyswiela metod

#piszemy raczej male funkcje

# od 10 do 20 z krokiem 2
for i in range (10, 20, 2):
    print(i)

l = [1,2,3,4,5,6,7,8,9]

print("-----------------")

for i in range(len(l)):
    print(l[i])


print("-----------------")

#lepszy sposob


for el in l:
    print(el)


print("-----------------")

# i - index, el - element listy
for i,el in enumerate(l):
    print(i,el)


d = {"sty":1, "lu":2, "mar": 3}
d["gru"] = 12

print("-----------------")


for k,v in d.items():
    print(k,v)

print("-----------------")


#list comprehension

l2 = [str(2*el) for el in l]
print(l2)


print("-----------------")



l3 = [str(2*el) for el in l if el %2]
print(l3)


print("-----------------")

#funckje

def f1(arg):
    arg +=2
    return arg if arg > 0 else -arg

print(f1(-100))
print(f1(3))


print("-----------------")


def f2(arg, x):
    arg +=2
    return arg +x if arg > 0 else x

print(f2(-10,45))
print(f2(3,4))



print("-----------------")

def f3(arg):
    def inner(c):
        return arg+c
    return inner


x = f3(10)
print(x(10))

def f5(f, a):
    return a, f(a)


print("-----------------")

def printer(f):
    def inner(x):
        print("uruchamiam: ", f.__name__)
        return f(x)
    return inner



fun = printer(f1)
print(fun(10))

#@printer
#def f10(x):

#@cache
#def f11(x):


#@user
#@gzip
#def f11(x):


#dir(f1) - wyswietla inf.


def colatz(p):
    n = p
    while n != 1:
        yield n
        n = n/2 if n%2 == 0 else 3*n + 1 #dokonczyc

# for i in colatz(200) dokonczyc

def fx(*a):
    for el in a:
        print(el)

fx(1,2,7,"hej")

def fy(x, y=0):
    print(x,y)


fy(3)
fy(3,4)
fy(4,y=4)

def f15(x, **kwargs):
    for k,v in kwargs.items()
    




