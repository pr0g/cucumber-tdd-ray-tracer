#ifndef TUPLE_H
#define TUPLE_H

struct Tuple
{
    Tuple() = default;
    Tuple(float x, float y, float z, float w) :
        x(x), y(y), z(z), w(w) {}

    float x;
    float y;
    float z;
    float w;
};

const Tuple operator+(const Tuple& lhs, const Tuple& rhs);

#endif // TUPLE_H
