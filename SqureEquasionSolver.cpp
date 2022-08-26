#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/solve_and_show.h"
#include "../headers/Unit_test.h"
#include "../headers/usefull_functions.h"

#include "../headers/rating.h"

#ifdef UNIT_TESTING
void Unit_test();
#endif

int main()
    {
    char repeat = 0;
    do
        {
        double a = NAN, b = NAN, c = NAN;
        get_coefficients(&a, &b, &c);

        double x1 = NAN, x2 = NAN;

        int number_of_roots = solve(a, b, c, &x1, &x2);

        show_result(number_of_roots, &x1, &x2);

        clear_buffer();

        printf("Press any key to continue or 'n' to stop ");
        repeat=getchar();
        system("cls");

        } while(repeat != 'n');

   // Rating
    rate();

}

