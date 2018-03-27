#include <iostream>
#include "myvector.hpp"
#include "functions.hpp"

void FillCards(vector &hand1, vector &hand2, vector &cards) {
    const int n_cards = 36;
    for (int i = 0; i < (n_cards); i++)
        vectorBack(cards, rand() % 9 + 1);
    for (int i = (n_cards) - 1; i > (n_cards / 2) - 1; i--)
        vectorBack(hand1, cards.data[i]);
    for (int i = (n_cards / 2) - 1; i >= 0; i--)
        vectorBack(hand2, cards.data[i]);
    vectorPrint(cards, std::cout);
    std::cout << std::endl;
    vectorPrint(hand1, std::cout);
    std::cout << std::endl;
    vectorPrint(hand2, std::cout);
}

void hand1win(vector &hand1, vector &hand2) {
    std::cout << "first win" << std::endl << hand1.data[hand1.used - 1] << " " << hand2.data[hand2.used - 1] << std::endl << "----" << std::endl;
    vectorInsert(hand2, 0, hand2.data[hand2.used - 1]);
    vectorInsert(hand2, 0, hand1.data[hand1.used - 1]);
    vectorPop(hand1);
    vectorPop(hand2);

}

void hand1win(vector &hand1, vector &hand2, int &j) {
    std::cout << "first win" << std::endl << hand1.data[hand1.used - 1] << " " << hand2.data[hand2.used - 1] << std::endl << "----" << std::endl;
    vectorInsert(hand2, 0, hand2.data[hand2.used - 1 - j]);
    vectorInsert(hand2, 0, hand1.data[hand1.used - 1 - j]);
    for (int i=0; i<j; i++) {
        vectorPop(hand1);
        vectorPop(hand2);
    }
}

void hand2win(vector &hand1, vector &hand2) {
    std::cout << "second win" << std::endl << hand1.data[hand1.used - 1] << " " << hand2.data[hand2.used - 1] << std::endl << "----" << std::endl;
    vectorInsert(hand1, 0, hand1.data[hand1.used - 1]);
    vectorInsert(hand1, 0, hand2.data[hand2.used - 1]);
    vectorPop(hand1);
    vectorPop(hand2);
}

void hand2win(vector &hand1, vector &hand2, int &j) {
    std::cout << "second win" << std::endl << hand1.data[hand1.used - 1 - j] << " " << hand2.data[hand2.used - 1 - j] << std::endl << "----" << std::endl;
    vectorInsert(hand1, 0, hand1.data[hand1.used - 1 - j]);
    vectorInsert(hand1, 0, hand2.data[hand2.used - 1 - j]);
    for (int i=0; i<j; i++) {
        vectorPop(hand1);
        vectorPop(hand2);
    }
}

void compare(vector &hand1, vector &hand2);

void draw(vector &hand1, vector &hand2) {
    std::cout << "draw" << std::endl << hand1.data[hand1.used - 1] << " " << hand2.data[hand2.used - 1] << std::endl << "----" << std::endl;
    compare(hand1, hand2);
}

int j = 1;
void compare(vector &hand1, vector &hand2) {
    if (hand1.data[hand1.used - j - 1] > hand2.data[hand2.used - j - 1]) {
        hand2win(hand1, hand2, j);
        j = 1;
    }
    else if (hand2.data[hand2.used - j - 1] > hand1.data[hand1.used - j - 1]) {
        hand1win(hand1, hand2, j);
        j = 1;
    }
    else {
        j++;
        draw(hand1, hand2);
    }
}



void Play(vector &hand1, vector &hand2) {
    do {
        if (hand1.data[hand1.used - 1] > hand2.data[hand2.used - 1])
            hand2win(hand1, hand2);
        else if (hand2.data[hand2.used - 1] > hand1.data[hand1.used - 1])
            hand1win(hand1, hand2);
        else draw(hand1, hand2);
    } while (!vectorEmpty(hand1) && !vectorEmpty(hand2));
}

void Win(vector &hand1, vector &hand2, vector &cards) {
    if (vectorEmpty(hand1))
        std::cout << "First win this game";
    else if (vectorEmpty(hand2))
        std::cout << "Second win this game";
    else
        std::cout << "Draw";
    vectorDestroy(hand1);
    vectorDestroy(hand2);
    vectorDestroy(cards);
}