// #include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "get_coefficients.h"

#define ERROR_SOLVER -2

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



//*************************************main function

int solve (double a, double b, double c, double *x1, double *x2)
    {

    assert(x1 != x2);
    assert(x1 != NULL && x2 != NULL);

    int number_of_roots = 0;

    //if linear equaition (a==0)
    if ( a == 0 )
        {
         number_of_roots = solve_linear(b, c, x1);
        *x2 = NAN;
        }

    //if square equation
    if ( a != 0 )
        {
        number_of_roots = solve_square(a, b, c, x1, x2);
        }


    return number_of_roots;

    }

/////////////////////////////////////////////end


/////********************solve linear
int solve_linear(double b, double c, double *x1)
    {

     // no roots
     if( b == 0 && c != 0){
        *x1 = NAN;
        return NO_ROOTS;
    }

    //1 root
    if (b != 0 && c != 0 )
        {
        *x1 = -c/b;
        return ONE_ROOT;
        }

    // ifinity roots
    if(b == 0 && c == 0)
        {
        *x1 = NAN;
        return INFINITE_ROOTS;
        }
    return ERROR_SOLVER;
    }
//////******************** solve square
int solve_square(double a, double b, double c, double *x1, double *x2)
    {
    int dis = (b*b - 4*a*c);
    if ( dis < 0 )
        {
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
        }

    if( dis == 0)
        {
        *x1 = - b / (2*a);
        *x2 = NAN;
        return ONE_ROOT;
        }

    if (dis > 0)
        {
        *x1 = (-b + sqrt(dis)) / (2*a);
        *x2 = (-b - sqrt(dis)) / (2*a);
        return TWO_ROOTS;
        }

    return ERROR_SOLVER;
    }

/////******************** show result
void show_result(int number_of_roots, double *x1, double *x2)
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
