// Napisz strukturę monadę CM, której celem jest
// zliczanie ilości kroków obliczeniowych wykonanych
// na danych wejściowych do otrzymania wyniku. Przykład kodu poniżej/po prawej. 

// double add2(double x) { return x+2; }

// double div3(double x) { return x/3; }



// double sq(double x) { return x*x; }

// double cube(double x) { return x*x*x; }

// // implementację tych funkcji zmiany tak żeby zwracały CM

// // która pozwala na takie sekwencyjne wywołanie funkcji:

// int main() {

//     CM a = CM(2).potem(add2).potem(sq).potem(sq);

//     std::cout << a.v << " ilosc operacji " << a.counter << std::endl;

//     CM b = a.potem(add2).potem(div3).potem(cube);

//     std::cout << b.v << " ilosc operacji " << b.counter << std::endl;

// }

// // wynik
// 256 ilosc operacji 3

// 636056 ilosc operacji 6


#include <iostream>
#include <functional>



// implementację tych funkcji zmiany tak żeby zwracały CM

// która pozwala na takie sekwencyjne wywołanie funkcji:

struct CM
{
    int v;
    int counter;

    CM(int a, int b = 0):
        v(a), counter(b) {};

    CM potem(std::function<CM(CM)> fun)
    {
        return fun(*this);
    }
  
        
};

CM add2(CM x) { x.v += 2; x.counter +=1; return x;}
CM div3(CM x) { x.v = x.v/3; x.counter+=1; return x ;}
CM sq(CM x) { x.v = x.v * x.v; x.counter +=1; return x;}
CM cube(CM x) { x.v = x.v * x.v * x.v; x.counter +=1; return x; }




int main() {

    CM a = CM(2).potem(add2).potem(sq).potem(sq);

    std::cout << a.v << " ilosc operacji " << a.counter << std::endl;

    CM b = a.potem(add2).potem(div3).potem(cube);

    std::cout << b.v << " ilosc operacji " << b.counter << std::endl;


    return 0;

}