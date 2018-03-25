#include "myvector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void vectorInit (vector &_vector, int _size) {
    _vector.data = new int[_size];
    _vector.size = _size;
    _vector.used = 0;
}

void vectorDestroy (vector &_vector) {
    delete[] _vector.data;
}

void vectorClear (vector &_vector) {
    _vector.used = 0;
}

bool vectorEmpty (vector &_vector) {
    return _vector.used == 0;
}

void vectorGrow (vector &_vector) {
    int vectorSizeNew = _vector.size * 2;
    int * vectorDataNew = new int[vectorSizeNew];

    memcpy (vectorDataNew, _vector.data, sizeof(int)*_vector.size);

    delete[] _vector.data;
    _vector.data = vectorDataNew;

    _vector.size = vectorSizeNew;
}

void vectorBack (vector &_vector, int _data) {
    if (_vector.used == _vector.size)
        vectorGrow(_vector);
    _vector.data[_vector.used++] = _data;
}

void vectorPop (vector &_vector) {
    assert(!vectorEmpty(_vector));
    --_vector.used;
}

void vectorRead (vector &_vector, std::istream &_stream) {
    while (true) {
        int temp;
        _stream >> temp;
        if (_stream)
            vectorBack(_vector, temp);
        else
            break;
    }
}

void vectorReadZero (vector &_vector, std::istream &_stream) {
    while (true) {
        int temp;
        _stream >> temp;
        if (_stream && temp != 0)
            vectorBack (_vector, temp);
        else
            break;
    }
}

void vectorPrint (const vector &_vector, std::ostream &_stream) {
    for (int i = 0; i < _vector.used; i++)
        _stream << _vector.data[i] << " ";
}

void vectorInsert (vector &_vector, int _position, int _data) {
    assert (_position >=0 && _position < _vector.used);
    int NewUsed = _vector.used + 1;
    if (NewUsed > _vector.size)
        vectorGrow(_vector);
    for (int i=_vector.used; i>_position; i--)
        _vector.data[i] = _vector.data[i-1];
    _vector.data[_position] = _data;
    _vector.used = NewUsed;
}

void vectorDelete (vector &_vector, int _position) {
    assert(_position >= 0 && _position < _vector.used);

    for (int i = _position + 1; i < _vector.used; i++)
        _vector.data[i-1] = _vector.data[i];

    --_vector.used;
}