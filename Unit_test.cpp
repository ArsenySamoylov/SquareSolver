#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "compare_double.h"
#include "solve_and_show.h"

int get_test(FILE *F_UNIT_TEST, double *a, double *b, double *c, double *root1, double *root2 );
void show_error( const double a,     const double b,     const double c,
                 const double root1, const double root2, const int number_of_roots,
                 const double x1,    const double x2,    const int num_of_rts);
int check( FILE *F_UNIT_TEST);

const int USELLES = 100;

////////////////////////////////////main function
void Unit_test()
    {
     FILE *F_UNIT_TESTS = fopen( "UNIT_TESTS.txt", "r" );
     // if file with tests doesn't exist
     if( F_UNIT_TESTS == NULL )
        {
        printf("File \"UNIT_TESTS.txt\" with unit test not found\n");
        return;
        }

     //get first uselles line
     char uselles[USELLES];
     fgets( uselles, USELLES, F_UNIT_TESTS );

     int Error_cnt = 0;

     while( !feof(F_UNIT_TESTS) )
        {
         int result = check(F_UNIT_TESTS);
         if (result == 0)
            Error_cnt++;
        }
     fclose(F_UNIT_TESTS);

      if ( Error_cnt == 0 )
        printf("Test finished without mistakes\n");

      printf("Occure %d errors in Unit Tests\n", Error_cnt);
    }
///////////////////////////////////end

void show_error( const double a,     const double b,     const double c,
                 const double root1, const double root2, const int number_of_roots,
                 const double x1,    const double x2,    const int num_of_rts)
     {

       printf("In equasion %lgx^2 + (%lg)x + (%lg) = 0 occured error\n", a, b, c);

       switch(number_of_roots)
            {
            case INFINITE_ROOTS:
                            printf("Expected INFINITE_ROOTS, OUTPUT: num_of_rts %d\n", num_of_rts );
                            break;

            case NO_ROOTS:  printf("Expected NO_ROOTS, OUTPUT: num_of_rts %d\n", num_of_rts );
                            break;

            case ONE_ROOT:  printf("Epected %lg, OUTPUT: num_of_rts %d rt1 = %lg\n", root1, num_of_rts, x1);
                            break;

            case TWO_ROOTS: printf("Epected %lg and %lg, OUTPUT: num_of_rts %d roots: %lg and %lg\n", root1, root2, num_of_rts, x1, x2);
                            break;
            default: printf("Unexpected error\n");
           }
        printf("\n\n");

     }

int get_test( FILE *F_UNIT_TESTS, double *a, double *b, double *c, double *root1, double *root2 )
    {
      fscanf(F_UNIT_TESTS, "%lg",a);
      fscanf(F_UNIT_TESTS, "%lg",b);
      fscanf(F_UNIT_TESTS, "%lg",c);

      int number_of_roots = -2;
      fscanf(F_UNIT_TESTS, "%d",&number_of_roots);

      if ( number_of_roots == 0 || number_of_roots == -1 )
        {
        *root1 = NAN;
        *root2 = NAN;
        }

      if ( number_of_roots == 1 )
        {
        fscanf(F_UNIT_TESTS, "%lg", root1);
        *root2 = NAN;
        }
      if ( number_of_roots == 2 )
        {
        fscanf(F_UNIT_TESTS, "%lg",root1);
        fscanf(F_UNIT_TESTS, "%lg",root2);
        }

      return number_of_roots;

    }
int check(FILE *F_UNIT_TESTS)
    {
     // data from test
     double a = NAN, b = NAN, c = NAN;
     double root1 = NAN, root2 = NAN;
     int number_of_roots = get_test( F_UNIT_TESTS, &a, &b, &c, &root1, &root2);

     double x1 = NAN, x2 = NAN;
     int num_of_rts = solve( a, b, c, &x1, &x2);

     //compare to data from test
     int flag = (number_of_roots == num_of_rts);
         flag *= ( (compare_double(x1, root1) == SAME) || (isfinite(x1) == 0 && isfinite(root1) == 0) );
         flag *= ( (compare_double(x2, root2) == SAME) || (isfinite(x2) == 0 && isfinite(root2) == 0) );
     if ( flag == 0 )
        {
        show_error(a, b, c, root1, root2, number_of_roots, x1, x2, num_of_rts);
        }
     return flag;

    }


