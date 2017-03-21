#include "hw1.h"

TriangleType CheckTriangle(int a, int b, int c)
{
	if ( a < 1 || a > MAX_EDGE || b < 1 || b > MAX_EDGE || c < 1 || c > MAX_EDGE )
        return INVALID;
    if ( a + b <= c || b + c <= a || a + c <= b )
        return INVALID;
    else if (a == b && a == c)
        return EQUILATERAL;
    else if ( (a == b && b != c) || (a == c && a != b) || (b == c && a != b) )
        return ISOSCELES;
    else
        return UNEQUAL;
}
