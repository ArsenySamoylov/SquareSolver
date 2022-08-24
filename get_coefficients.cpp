// #include <TXLib.h>
#include <stdio.h>
#include <assert.h>

void get(double *n);
void get_coefficients(double *a, double *b, double *c);

//*************************************main function

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

/////////////////////////////////////////////end


void get(double *n)
    {

    if (scanf("%lf", n) == 0)
        {

        // clear buffer
        getchar();

        printf("Please, enter coefficient again: ");
        get(n);

        }
    return;
    }
