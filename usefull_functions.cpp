#include <stdio.h>
#include <math.h>

#include "../headers/usefull_functions.h"

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

void clear_buffer()
    {
     while( getchar() != '\n' );
    }
