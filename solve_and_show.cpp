#include <math.h>
#include <stdio.h>

#include "../headers/usefull_functions.h"

#include "../headers/solve_and_show.h"


int solve (const double a, const double b, const double c, double *x1, double *x2)
    {

    Assert_Custom(x1 != NULL && x2 != NULL);
    Assert_Custom(x1 != x2);
    Assert_Custom( (isfinite(a) && isfinite(b) && isfinite(c)) );

    int number_of_roots = 0;

    //if linear equaition (a==0)
    if ( compare_double(a,0) == SAME )
        {
         number_of_roots = solve_linear(b, c, x1);
        *x2 = NAN;

        return number_of_roots;
        }

    //if square equation
    number_of_roots = solve_square(a, b, c, x1, x2);

    return number_of_roots;

    }


int solve_linear( const double b, const double c, double *x1)
    {

     // no roots or infinite roots
     if( compare_double(b,0) == SAME )
        {
        *x1 = NAN;

        if( compare_double(c,0) == SAME )
            return INFINITE_ROOTS;

        return NO_ROOTS;
        }

     //1 root
     *x1 = -c / b;
     return ONE_ROOT;

    }


int solve_square( const double a, const double b, const double c, double *x1, double *x2)
    {
    double dis = (b*b - 4*a*c);
    if( compare_double(dis, 0) == FIRST_LOWER )
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

    // dis > 0
    double sqrt_dis = sqrt(dis);

    double root1 = (-b + sqrt_dis) / (2*a),
           root2 = (-b - sqrt_dis) / (2*a);

    // in ascending order root1 < root2
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


void show_result( const int number_of_roots, const double *x1,  const double *x2)
    {
     switch(number_of_roots)
            {
            case NO_ROOTS:  printf("Equation has no roots\n");
                            break;

            case ONE_ROOT:  printf("Equation has 1 root: %lg\n",*x1);
                            break;

            case TWO_ROOTS: printf("Equation has 2 roots: %lg and %lg\n",*x1, *x2);
                            break;

            case INFINITE_ROOTS:
                            printf("You can choose ANY number\n");
                            break;

            case ERROR_SOLVER:

            default:          printf("PROBLEM with solve-function\n");
                              printf("WTF???\n");
            }
    }

void get_coefficients(double *a, double *b, double *c)
    {

    printf( "Enter coefficients a,b,c for equation: Ax^2 + Bx + C =0\n");

    printf( "Enter A: ");
    get(a);

    printf( "Enter B: ");
    get(b);

    printf ("Enter C: ");
    get(c);

    return;

    }


void get(double *n)
    {

    while ( scanf("%lg", n) == 0 )
        {

        clear_buffer();

        printf("Please, enter coefficient again: ");

        }
    return;
    }
