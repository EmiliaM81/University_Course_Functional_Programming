// Zakładamy że mamy zestaw funkcji typu double -> double. 
//  naszym projekcie musimy zacząć pracować nagle na danych 
//  wielowymiarowych zapisanych w strukturze: struct D { double x1, x2, x3; };
// Napisz funkcje wyższego rzędu, która powoli zastosować nasze funkcje do danych typu D.
// dane są na przykład:
// double sq(double x) { return x*x; }; double neg(double x) { return -x; } ….etc
// auto sqD = toD(sq); auto negD = toD(neg); /// tu tworzymy nowe funkcje
// D d1(10, 4, 5);
// D d2 = sqD(d1);
// D d3 = negD(d2);

#include <iostream>
#include <functional>

struct D
{
    double x1;
    double x2;
    double x3;

    D(double x = 0, double y =0, double z = 0)
        : x1(x), x2(y), x3(z) 
        {};
};

std::function<D(const D &)> toD(std::function<double(double)> fun)
{
    return [fun](const D &d)
    {
        D result;
        result.x1 = fun(d.x1);
        result.x2 = fun(d.x2);
        result.x3 = fun(d.x3);
        return result;
    };
}


double sq(double x) 
{ 
    return x*x; 
};

double neg(double x) 
{ 
    return -x; 
}

auto sqD = toD(sq); 
auto negD = toD(neg); 

int main()
{
    D d1(10, 4, 5);
    D d2 = sqD(d1);
    D d3 = negD(d2);



    return 0;
}