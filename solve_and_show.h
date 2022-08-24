#ifndef SOLVE_AND_SHOW_H_INCLUDED
#define SOLVE_AND_SHOW_H_INCLUDED


    enum ROOTSNUMBER
    {
    NO_ROOTS= 0,
    ONE_ROOT =  1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
    };

    int solve_linear(double b, double c, double *x1);
    int solve_square(double a, double b, double c, double *x1, double *x2);
    void show_result(int number_of_roots, double *x1, double *x2);
    int solve (double a, double b, double c, double *x1, double *x2);


    //include get_coefficient
    #include "get_coefficients.h"

#endif
