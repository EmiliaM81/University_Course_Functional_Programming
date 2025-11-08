#include <iostream>
#include <functional>

bool czy_jest(int *begin, int* past_end, int value);



bool czy_jest1(int *begin, int* past_end, std::function<bool (int)>f);

int czy_jest2(int *begin, int* past_end, std::function<bool (int)>f, int buff);

double suma_ulamkow1(int n, double sum, double eps);


double suma_ulamkow(double eps);



int main()
{
    int tab[] = {0,10,2,100,4,5};

    
    
    
    



    std::cout << "\n-----------Zadanie 1---------\n";

    bool isTrue0 = czy_jest(tab, tab+5, 2);
    bool isTrue01 = czy_jest(tab, tab+5, 2000);
    
    std::cout << "\n-----------Zadanie 2---------\n";
    

    bool isTrue1 = czy_jest1(tab, tab+5, [](int el){ return el >5; });


    std::cout << "\n-----------Zadanie 3---------\n";

    int elementy = czy_jest2(tab, tab+5, [](int el){ return el >5; }, 0);



    std::cout << "\n-----------Zadanie 4---------\n";

    double sumUl = suma_ulamkow(1e-6);
    







    return 0;
}


bool czy_jest(int *begin, int* past_end, int value)
{
    

    std::cout << "W podanej tablicy nie znajduje się element: " << value << '\n';
    return false;
}


bool czy_jest1(int *begin, int* past_end, std::function<bool (int)>f)
{
  

   int len = past_end - begin;

    for (int i=0; i<len; i++)
    {
        if (f(begin[i]))
        {
            std::cout << "W podanej tablicy znajduje się element wiekszy niz 5\n";
            return true;
        }
    }

    std::cout << "W podanej tablicy nie znajduje się element wiekszy niz 5\n";
    return false;
}

int czy_jest2(int *begin, int* past_end, std::function<bool (int)>f, int buff)
{

    
    if (begin == past_end)
    {
        std::cout << "Ilosc elementow w tablicy mniejszych niz 5: " << buff<<"\n";
        return buff;
    }

    if (f(begin[0]))
    {

        buff ++;
    }

    return czy_jest2(begin+1, past_end, f, buff);

    
}

double suma_ulamkow1(int n, double sum, double eps)
{
    double val = 1.0/n;

    if (val < eps)
    {
        std::cout<< "Suma ulamkow wiekszych niż "<< eps <<" : " << sum << '\n';
        return sum;
    }

    return suma_ulamkow1(n+1, sum+val, eps);
}


double suma_ulamkow(double eps)
{
    return suma_ulamkow1(1, 0.0, eps);
}
