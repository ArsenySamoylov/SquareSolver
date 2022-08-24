#include <math.h>

const double EPSILON = 1e-6;

int is_equal_double( double b, double c)
    {
     return  fabs( b - c) < EPSILON ? 1 : 0 ;
    }
