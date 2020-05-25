#include "test.h"
#include <math.h>
int assert_equals_int(int got, int expected)
{
    return got == expected;
}
int assert_equals_float(float got, float expected, float epsilon)
{
    return fabs(expected - got) <= epsilon;
}