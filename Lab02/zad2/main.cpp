// Z użyciem kontenera LazyFunctionalVector obudowującego tablicę
// napisów (może być vector<string>) z zawartością: Ala ma kota a kot ma myszkę 
// wyliczy ilość znaków zawartych we wszystkich
// słowach dłuższych niż 3 (filter, map, sum)
// najdłuższe słowo
// najdłuższe słowo na literę ‘k’
// wszystkie słowa na ‘m’ złączone w jedno słowo
// sprawdzić czy wsród słów wszystkie zawierają literą ‘a’
// sprawdzić czy jakieś słowo ma długość większą niż 5


#include <iostream>
#include "LazyFunctionalVector.h"
#include <vector>
#include <string>

using namespace lfv;
int main() {
    int data1 [8] = {1,4,5,6,7,-7,0,-1};
    int data2 [7] = {5,4,3,6,7,4,4};
    auto d1 = lazy_view(data1, 8);
    d1.foreach(S(std::cout << _ << ", "));
    auto d2 = lazy_view(data2, 7);
    d2.foreach(S(std::cout << _ << ":"));
    std::cout << std::endl << d1.filter(F(_<0)).sum() << std::endl;


    std::vector<std::string> words =  {"Ala", "ma", "kota", "a", "koa", "ma", "myszkę"};

    auto container = lazy_view(words);

// wyliczy ilość znaków zawartych we wszystkich
// słowach dłuższych niż 3 (filter, map, sum) 

    int countLongerThree = container
                            .filter(F(_.length()>3))
                            .map( F(_.length()))
                            .sum();

    std::cout << "wyliczy ilość znaków zawartych we wszystkich słowach dłuższych niż 3 (filter, map, sum)" << countLongerThree << "\n";


// najdłuższe słowo

    std::string longestWord = container 
                        .max(F(_.length()))
                        .get()
                        .value();

std::cout << "najdłuższe słowo " << longestWord << "\n";

// najdłuższe słowo na literę ‘k’

    std::string longestWordK = container 
                        .filter(F(_[0] == 'k' || _[0] == 'K'))
                        .max(F(_.length()))
                        .get()
                        .value();

std::cout << "najdłuższe słowo na literę 'k' " << longestWordK << "\n";

// wszystkie słowa na ‘m’ złączone w jedno słowo

    std::string allWordsM = container
                            .filter( F(_[0] == 'm' || _[0] == 'M'))
                            .sum();

std::cout << "wszystkie słowa na 'm' złączone w jedno słowo " << allWordsM << "\n";


// sprawdzić czy wsród słów wszystkie zawierają literą ‘a’

bool allStartWithA = container
                        .all(F(_.find('a') != std::string::npos));

std::cout << "Sprawdzić czy wsród słów wszystkie zawierają literą 'a' " << allStartWithA << "\n";


// sprawdzić czy jakieś słowo ma długość większą niż 5

bool longerThanFive = container
                        .max(F(_.length()))
                        .get()
                        .value()
                        .length() > 5;

std::cout << "sprawdzić czy jakieś słowo ma długość większą niż 5 " << longerThanFive << "\n"; 

    return 0;
}