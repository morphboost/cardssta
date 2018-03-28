#include <iostream>

struct deque {
    char * data;
    int used;
    int size;
};

void dequeInit (deque &_deque, int _size = 10);
void dequePushBack (deque &_deque, char &_data);
void dequePushFront (deque &_deque, char &_data);
void dequePopBack (deque &_deque);
void dequePopFront (deque &_deque);
void dequePrint (deque &_deque, std::ostream &_stream);
void dequeDestroy (deque &_deque);
bool dequeEmpty (deque &_deque);