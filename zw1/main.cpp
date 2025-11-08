// Type your code here, or load an example.
#include <string>
#include <iostream>
#include <functional>

struct osoba {
    std::string imie;
    int wiek = -1;
    void ustWiek (int w)
    {
        wiek = w;
    }

    osoba(std::string i, int w)
    {
        imie = i;
        wiek = w;
    }

    osoba()
    {
        imie = "noname";
        wiek = -999;
    }
};




template <typename T>
T dodaj2(T x)
{
    return x+2;
}

template <typename T>
T pom2(T x)
{
    return x*2;
}




std::function <int (int)> comp(std::function <int (int)> f1, std::function <int (int)> f2)
{
    return [f1, f2](int a)->int{return f1(f2(a));};
}






int tr (std::function <int (int)>f ,int x)
{
    return f(x);
}


int wr(std::function <int (int)> f, int x)
{
    int tmp  = f(x);
    std::cout << "f(" << x << ") = " << tmp << '\n';
    return tmp;
}




std::function <int (int) > wr2(std::function<int (int)>f)
{
    std::cout <<"_\n";
    auto n = [f](int a)->int{
        int tmp = f(a);
        std::cout << "f(" << a << ") = " << tmp << '\n';

        return tmp;
    };

    return n;
}


template <typename A, typename R>
std::function <R (A) > wr3(std::function<R (A)>f);


template <typename F>
F wr4(F f);








void trArr(std::function <int (int)>f, int *arr, int n); 






// aplikuje funkcje f do kazdego elementu tablicy
//dokonczyc
void map (int* in, int* out, int n, std::function<int(int)>f)
{
    for (int i=0; i<n; i++)
    {
        out[i] = f(in[i]);
    }
}

//dokonczyc
void filter (int* in, int* out, int n, std::function<bool(int)>f)
{
    for (int i=0; i<n; i++)
    {
        out[i] = f(in[i]);
    }  
}


//dokonczyc
void reduce (int* in, int n, std::function<int(int,int)>f)
{

}


int main()
{

    std::cout<<"hej\n";

    osoba ty("Jan", 30);
    osoba ja("Emilia", 20);

    ja.ustWiek(20);

    ja.wiek = 19;

    osoba ja1;
    

    std::cout<< ja1.imie << " " << ja1.wiek << std::endl;
    std::cout<< ja.wiek << " " << ty.wiek << std::endl;

    std::cout << dodaj2(3.0) << '\n';
    std::cout << dodaj2(3) << '\n';
    std::cout << dodaj2("Hej") << '\n'; // traktuje to jako wskaznik char 
    // wychodzi blad std::cout << dodaj2(std::string ("Hej")) << '\n';


    //auto f2 = [](int x){ return x+2; };
    //auto f2 = [](auto x){ return x+2; };
    //auto f2 = [](int x)->int{ return x+2; }; // -> int - zawsze zwraca int



    


    std::function<int (int)> f2 = [](auto x)->int{ return x+2; }; // <int (int) > - funkcja zwaca int i pobiera int (potrzbujemy do tego naglowka functional)
    
    std::cout << f2(10.0) << '\n';

    std::cout << tr(f2, 100) << "\n";
    std::cout << wr(f2, 7) << "\n";

    auto f2w = wr2(f2);
    std::cout << f2w(15);


    std::cout << "\n-------------------------------\n";


   std::function <int (int)> myFunc = comp(dodaj2<int>, dodaj2<int>);

   std::cout << "Myfunc(5) = " << myFunc(5) << '\n';

    return 0;
}