def gen(a, b, m, seed = 1):
    state = seed
    while(True):
        state =( a * state + b )% m 
        yield state


gen1 = gen(3, 5, 1000)
gen2 = gen(4, 5, 1000)



result = True

l1 = (next(gen1) for i in range (1000))
l2 = (next(gen2) for i in range (1000) )

wyn = zip(l1 , l2 )

for val1, val2 in wyn:
    if (val1 - val2) != 0:
        result = False
        break

print("W pierwszym 1000 wszystkie roznice miedzy wtgenerowanymi wartosciami sa rowne 0: ", result)
