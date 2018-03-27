#include <iostream>
#include "myvector.hpp"
#include "functions.hpp"
#include <fstream>

int main() {
    std::string filenamE;
    std::cin >> filenamE;
    std::ofstream{filenamE};
    vector hand1,hand2,cards;
    vectorInit(hand1,10);
    vectorInit(hand2,10);
    vectorInit(cards,10);
    FillCards(hand1,hand2,cards);
    Play(hand1, hand2);
    Win(hand1,hand2,cards);
    std::ofstream c(filenamE);
}