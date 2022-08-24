// #include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "solve_and_show.h"

// old version
//#include "solve_square_equation.cpp"
//#include "get_coefficients.h"
 #include "rating.h"

int main()
    {
    char repeat = 0;
    do{
        double a = NAN, b = NAN, c = NAN;
        get_coefficients(&a, &b, &c);

        double x1 = NAN, x2 = NAN;

        int number_of_roots = solve(a, b, c, &x1, &x2);

        show_result(number_of_roots, &x1, &x2);

        getchar();
        printf("Press any key to continue or 'n' to stop ");
        repeat=getchar();
        system("cls");

        }while(repeat != 'n');

   // Rating
   // в разработке
    rate();

}

