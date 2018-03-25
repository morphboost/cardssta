#include <iostream>
#include "myvector.hpp"

void FillCards(vector &hand1, vector &hand2, vector &cards) {
    const int n_cards = 36;
    for (int i=0; i<(n_cards); i++)
        vectorBack(cards, rand()%8+1);
    for (int i=(n_cards)-1; i>(n_cards/2)-1; i--)
        vectorBack(hand1, cards.data[i]);
    for (int i=(n_cards/2)-1; i>=0; i--)
        vectorBack(hand2, cards.data[i]);
    vectorPrint(cards, std::cout);
    std::cout << std::endl;
    vectorPrint(hand1, std::cout);
    std::cout << std::endl;
    vectorPrint(hand2, std::cout);
    std::cout << std::endl;
}

void Win(vector &hand1, vector &hand2, vector &cards) {
    if (vectorEmpty(hand1))
        std::cout << "First win";
    else if (vectorEmpty(hand2))
        std::cout << "Second win";
    else
        std::cout << "Draw";
    vectorDestroy(hand1);
    vectorDestroy(hand2);
    vectorDestroy(cards);
}

void Draw(vector &hand1, vector &hand2, int &i, int j = 1) {

}

void Play(vector &hand1, vector &hand2, int i = 0) {
    do {
        if (hand1.data[hand1.used - 1] > hand2.data[hand2.used - 1]) {
            std::cout << "second win" << std::endl << hand1.data[hand1.used - 1] << " " << hand2.data[hand2.used - 1] << std::endl << "----" << std::endl;
            vectorInsert(hand1, 0, hand1.data[hand1.used - 1]);
            vectorInsert(hand1, 0, hand2.data[hand2.used - 1]);
            vectorPop(hand1);
            vectorPop(hand2);
            i++;
        } else if (hand2.data[hand2.used - 1] > hand1.data[hand1.used - 1]) {
            std::cout << "first win" << std::endl << hand1.data[hand1.used - 1] << " " << hand2.data[hand2.used - 1] << std::endl << "----" << std::endl;
            vectorInsert(hand2, 0, hand2.data[hand2.used - 1]);
            vectorInsert(hand2, 0, hand1.data[hand1.used - 1]);
            vectorPop(hand1);
            vectorPop(hand2);
            i++;
        } else {
            Draw(hand1, hand2, i);
        }
    } while (!vectorEmpty(hand1) || !vectorEmpty(hand2));
}

int main()
{
    vector hand1,hand2,cards;
    vectorInit(hand1,10);
    vectorInit(hand2,10);
    vectorInit(cards,10);
    FillCards(hand1,hand2,cards);
    Play(hand1, hand2);
    Win(hand1,hand2,cards);
}