// #include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "get_coefficients.h"

static const int INFINITE_ROOTS = -1;
static const int ERROR_SOLVER=-2;

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
        return 0;
    }

    //1 root
    if (b != 0 && c != 0 )
        {
        *x1 = -c/b;
        return 1;
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
        return 0;
        }

    if( dis == 0)
        {
        *x1 = - b / (2*a);
        *x2 = NAN;
        return 1;
        }

    if (dis > 0)
        {
        *x1 = (-b + sqrt(dis)) / (2*a);
        *x2 = (-b - sqrt(dis)) / (2*a);
        return 2;
        }

    return ERROR_SOLVER;
    }

/////******************** show result
void show_result(int number_of_roots, double *x1, double *x2)
    {
     switch(number_of_roots)
            {
            case 0: printf("Equation has no roots\n");
                    break;
            case 1: printf("Equation has 1 root: %lg\n",*x1);
                    break;
            case 2: printf("Equation has 2 root: %lg and %lg\n",*x1, *x2);
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
