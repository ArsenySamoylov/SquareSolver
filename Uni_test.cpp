#include <stdio.h>
#include <stdlib.h>

#include "is_equal_double.h"

int get_test(FILE *f, double *a, double *b, double *c, double *root1, double *root2 );
void show_error( double a, double b, double c, double root1, double root2, double x1, double x2);

////////////////////////////////////main function
void Unit_test()
    {
     FILE *f;
     f = fopen( "UNIT_TESTS.txt", "r" );
     //get firs uselles line
     char uselles[100];
     fgets( uselles, 100, f );

     while( !feof(f) )
        {
         double a = NAN, b = NAN, c = NAN,
                root1 = NAN, root2 = NAN;

         int number_of_roots = get_test( &a, &b, &c, &root1, &root2 );

         double x1 = NAN, x2 = NAN;
         int flag = 1;

         if( number_of_roots != solve( a, b, c, &x1, &x2 ) )
            flag = 0;

         if( (numer_of_roots == ONE_ROOT) && (is_equal(root1, x1) != 1) )
            flag = 0;

         if( (number_of_roots == TWO_ROOTS) && (is_equal(root1, x1) != 1) && (is_equal(root2, x2) != 1) )
            flag = 0;

         if( flag )
            show_error( a, b, c, root1, root2, x1, x2);
        }
    fclose(f);
    }
///////////////////////////////////end

void show_error( double a, double b, double c, double root1, double root2, double x1, double x2)
     {
       printf("Err occured, a = %lg, b = %lg, c = %lg\n");

            switch(number_of_roots)
                {
                case NO_ROOTS:  printf("Expected NO_ROOTS\n");
                                break;

                case ONE_ROOT:  printf("Epected %lg, OUTPUT: %lg\n", root1, x1);
                                break;

                case TWO_ROOTS: printf("Epected %lg and %lg, OUTPUT: %lg\n and %lg\n", root1, root2, x1, x2);
                                break;
                default: printf("Unexpected error\n");
               }
     }

int get_test(FILE *f, double *a, double *b, double *c, double *root1, double *root2 )
    {
      fscanf(f, "%lg",a);
      fscanf(f, "%lg",b);
      fscanf(f, "%lg",c);
      fscanf(f, "%lg",root1);
      fscanf(f, "%lg",root2);

      int number_of_roots=-1;
      fscanf(f, "%d",&number_of_roots);
      return number_of_roots;

    }
