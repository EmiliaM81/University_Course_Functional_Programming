l = [1,4,5,23,12,26,23,17]



def group_by(fun, tab):
    res={}
    for i in tab:

        res.setdefault(fun(i), []).append(i)
        #res[k].append(i)

    return res

res = group_by(lambda x: int(int(x)/10), l)


print(res)