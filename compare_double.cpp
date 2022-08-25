#include <math.h>
#include <stdio.h>

const double EPSILON = 1e-6;

enum COMPARE
     {
     FIRST_BIGGER,
     SAME,
     FIRST_LOWER,
     ERROR_COMPARISON
     };

int compare_double( const double a, const double b)
    {
     if ( (a - b) > EPSILON )
        return FIRST_BIGGER;

     if ( (b - a) > EPSILON )
        return FIRST_LOWER;

    if  ( fabs(a-b) < EPSILON )
        return SAME;

    return ERROR_COMPARISON;
    }


