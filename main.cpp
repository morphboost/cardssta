#include <iostream>
#include "deque.hpp"

void FillDeque (deque &hand1, deque &hand2, int &n_cards) {

    const char letters[] = "6789TJQKA";
    for (int i=0; i<(n_cards/2); i++) {
        char x = letters[rand() % 9];
        dequePushBack(hand1, x);
    }

    for (int i=0; i<(n_cards/2); i++) {
        char x = letters[rand() % 9];
        dequePushBack(hand2, x);
    }

    dequePrint(hand1, std::cout);
    std::cout << std::endl;
    dequePrint(hand2, std::cout);
}

int compare (deque &hand1, deque &hand2) {
    if (hand1.data[0] > hand2.data[0])
        return 2;
    else if (hand1.data[0] < hand2.data[0])
        return 1;
    else
        return 0;
}

void hand1win (deque &hand1, deque &hand2) {
    std::cout << std::endl << hand1.data[0] << ' ' << hand2.data[0] << "\nHand 1 win\n-----";
    dequePushBack(hand2, hand2.data[0]);
    dequePushBack(hand2, hand1.data[0]);
    dequePopFront(hand1);
    dequePopFront(hand2);
    std::cout << std::endl;
    dequePrint(hand1, std::cout);
    std::cout << std::endl;
    dequePrint(hand2, std::cout);
}

void hand2win (deque &hand1, deque &hand2) {
    std::cout << std::endl << hand1.data[0] << ' ' << hand2.data[0] << "\nHand 2 win\n-----";
    dequePushBack(hand1, hand1.data[0]);
    dequePushBack(hand1, hand2.data[0]);
    dequePopFront(hand1);
    dequePopFront(hand2);
    std::cout << std::endl;
    dequePrint(hand1, std::cout);
    std::cout << std::endl;
    dequePrint(hand2, std::cout);
}

void draw (deque &hand1, deque &hand2) {

}

void Play (deque &hand1, deque &hand2) {
    do {
        if (compare(hand1, hand2) == 1)
            hand1win(hand1, hand2);
        else if (compare(hand1, hand2) == 2)
            hand2win(hand1, hand2);
        else
            draw;
    } while (!dequeEmpty(hand1) || !dequeEmpty(hand2));
}


int main() {
    int n_cards = 36;

    deque cards;
    dequeInit(cards, n_cards);
    deque hand1;
    dequeInit(hand1, n_cards);
    deque hand2;
    dequeInit(hand2, n_cards);

    FillDeque(hand1, hand2, n_cards);
    Play(hand1, hand2);
}

/*
 *     std::cout << std::endl;
    dequePrint(hand1, std::cout);
    std::cout << std::endl;
    dequePrint(hand2, std::cout);
 */