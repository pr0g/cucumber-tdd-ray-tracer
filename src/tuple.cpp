#include "tuple.h"

const Tuple operator+(const Tuple& lhs, const Tuple& rhs)
{
    return Tuple(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}
