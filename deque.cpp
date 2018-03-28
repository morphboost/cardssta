#include <iostream>
#include "deque.hpp"
#include <cassert>

void dequeInit (deque &_deque, int size) {
    _deque.data = new char[size];
    _deque.size = size;
    _deque.used = 0;
}

void dequeDestroy (deque &_deque) {
    delete[] _deque.data;
}

bool dequeEmpty (deque &_deque) {
    return _deque.used == 0;
}

void dequeGrow (deque &_deque) {
    int newsize = _deque.size * 2;
    char *newdata = new char[newsize];

    memcpy(newdata, _deque.data, sizeof(char) * _deque.size);

    delete[] _deque.data;

    _deque.size = newsize;
}

void dequePushBack (deque &_deque, char &_data) {
    if (_deque.used == _deque.size)
        dequeGrow(_deque);

    _deque.data[_deque.used++] = _data;
}

void dequePushFront (deque &_deque, char &_data)
{
    int newUsed = _deque.used + 1;
    if (newUsed > _deque.size)
        dequeGrow(_deque);

    for ( int i = _deque.used; i > 0; i-- )
        _deque.data[i] = _deque.data[i-1];

    _deque.data[0] = _data;

    _deque.used = newUsed;
}

void dequePopBack (deque &_deque) {
    assert (!dequeEmpty(_deque));

    --_deque.used;
}

void dequePopFront (deque &_deque) {
    assert (0 < _deque.used);

    for (int i = 1; i < _deque.used; i++)
        _deque.data[i-1] = _deque.data[i];

    --_deque.used;
}

void dequePrint (deque &_deque, std::ostream &_stream) {
    for (int i=0; i<_deque.used; i++)
        _stream << _deque.data[i] << " ";
}