#include <iostream>


struct vector
{
    int *data;
    int size;
    int used;
};

void vectorInit (vector &_vector, int _size);

void vectorDestroy (vector &_vector);

void vectorClear (vector &_vector);

bool vectorEmpty (vector &_vector);

void vectorGrow (vector &_vector);

void vectorBack (vector &_vector, int _data);

void vectorPop (vector &_vector);

void vectorRead (vector &_vector, std::istream &_stream);

void vectorReadZero (vector &_vector, std::istream &_stream);

void vectorPrint (const vector &_vector, std::ostream &_stream);

void vectorInsert (vector &_vector, int _position, int _data);

void vectorDelete (vector &_vector, int _position);

bool myvectorEmpty (vector &_vector);