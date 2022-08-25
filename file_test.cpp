#include <stdio.h>
#include <stdlib.h>

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

int main()
    {

    FILE *f;
    f = fopen( "UNIT_TESTS.txt", "r" );
    char uselles[100];
    fgets( uselles, 100, f );

    double a,b,c,r1,r2;

    while( !feof(f) )
    {
    int num = get_test(f, &a,&b,&c,&r1, &r2);
    printf("%lg %lg %lg %lg %lg %d\n", a,b,c,r1,r2,num)  ;
    }
    //int number = get_test(f,&a,&b,&c,&r1,&r2);
   fclose(f);

     }
