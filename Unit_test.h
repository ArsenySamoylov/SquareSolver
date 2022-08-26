#ifndef UNIT_TEST
#define UNIT_TEST

    /**

     \brief This functions runs unit test from file "UNIT_TEST.txt"

    */
    void Unit_test();

    /**
     \brief This functions checks data from test and data from function solve

     @param [in] F_UNIT_TESTS pointer to file with tests

     \return 1 if test passed and
             0 if error occurred

        This function take data for test: input values for function solve and
        values, that expected to be returned from solve
        If expected values and values from solve differ, then function would call
        show_error function, to show information about error and
        return 0, as signal that error occurred
    */
    int check( FILE *F_UNIT_TESTS);

    /**
     \brief This function extract data from file with tests

     @param [in] F_UNIT_TESTS pointer to file with  tests
     @param [out] a pointer to variable coefficient before x^2
     @param [out] b pointer to variable that contains coefficient before x
     @param [out] c pointer to variable that contains parametr
     @param [out] root1 pointer to variable that contains solution to equation
     @param [out] root2 pointer to variable that contains solution to equation

     \return number of roots of equation

     This function extract coefficients from test data, number of roots and
     depending on this exctract data about roots
     (if root doesn't exists than for it's variable assign NAN value)

     <b>!NB THIS FUNCTION DOESN'T CHECK FILES DATA FOR ERRORS!</b>
    */
    int get_test(FILE *F_UNIT_TESTS, double *a, double *b, double *c, double *root1, double *root2 );

    /**
     \brief This function shows information about test if error occurred

     @param [in] a coefficient before x^2
                 from test data
     @param [in] b coefficient before x
                 from test data
     @param [in] c parameter in equation
                 from test data
     @param [in] root1 equation's root
                 from test data
     @param [in] root2 equation's root
                 from test data
     @param [in] number_of_roots
                 from test data

     @param [in] x1 equation's root
                 from function solve
     @param [in] x2 equation's root
                 from function solve
     @param [in] num_of_rts num_of_rts
                 from function solve

     \return void
    */
    void show_error( const double a,     const double b,     const double c,
                 const double root1, const double root2, const int number_of_roots,
                 const double x1,    const double x2,    const int num_of_rts);

#endif
