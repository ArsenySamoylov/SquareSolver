// #include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "get_coefficients.h"
#include "compare_double.h"

#define ERROR_SOLVER -2

enum ROOTSNUMBER
    {
    NO_ROOTS= 0,
    ONE_ROOT =  1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
    };

int solve_linear( const double b, const double c, double *x1);
int solve_square( const double a, const double b, const double c, double *x1, double *x2);
void show_result( const int number_of_roots, const double *x1, const double *x2);



//*************************************main function

int solve (const double a, const double b, const double c, double *x1, double *x2)
    {

    assert(x1 != x2);
    assert(x1 != NULL && x2 != NULL);

    int number_of_roots = 0;

    //if linear equaition (a==0)
    if ( compare_double(a,0) == SAME )
        {
         number_of_roots = solve_linear(b, c, x1);
        *x2 = NAN;
        }

    //if square equation
    if ( !(compare_double(a,0) == SAME) )
        {
        number_of_roots = solve_square(a, b, c, x1, x2);
        }


    return number_of_roots;

    }

/////////////////////////////////////////////end


/////********************solve linear
int solve_linear( const double b, const double c, double *x1)
    {

     // no roots or infinite roots
     if( compare_double(b,0) == SAME )
        {
        *x1 = NAN;

        if ( compare_double(c,0) == SAME )
            return INFINITE_ROOTS;

        return NO_ROOTS;
        }

    //1 root
    *x1 = -c/b;
    return ONE_ROOT;

    }
//////******************** solve square
int solve_square( const double a, const double b, const double c, double *x1, double *x2)
    {
    int dis = (b*b - 4*a*c);
    if ( compare_double(dis, 0) == FIRST_LOWER )
        {
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
        }

    if( compare_double(dis,0) == SAME )
        {
        *x1 = - b / (2*a);
        *x2 = NAN;

        return ONE_ROOT;
        }

    if ( compare_double(dis,0) == FIRST_BIGGER )
        {
        double sqrt_dis = sqrt(dis);
        double root1 = (-b + sqrt_dis) / (2*a),
               root2 = (-b - sqrt_dis) / (2*a);
        if ( compare_double(root1,root2) == FIRST_LOWER )
            {
            *x1 = root1;
            *x2 = root2;
            }
        else
            {
            *x1 = root2;
            *x2 = root1;
            }
        return TWO_ROOTS;
        }

    return ERROR_SOLVER;
    }

/////******************** show result
void show_result( const int number_of_roots, const double *x1,  const double *x2)
    {
     switch(number_of_roots)
            {
            case NO_ROOTS: printf("Equation has no roots\n");
                    break;

            case ONE_ROOT: printf("Equation has 1 root: %lg\n",*x1);
                    break;

            case TWO_ROOTS: printf("Equation has 2 root: %lg and %lg\n",*x1, *x2);
                    break;

            case INFINITE_ROOTS:
                    printf("You can choose ANY number\n");
                    break;

            case ERROR_SOLVER:
                    printf("PROBLEM with solve-function\n");
                    break;

            default: printf("WTF???\n");
            }
    }
