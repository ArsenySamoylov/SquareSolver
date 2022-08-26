#ifndef SOLVE_AND_SHOW_H_INCLUDED
#define SOLVE_AND_SHOW_H_INCLUDED

#define ERROR_SOLVER (-2)

    enum ROOTSNUMBER
    {
    NO_ROOTS= 0,
    ONE_ROOT =  1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
    };

    /**
     \brief This function solves equasion: ax^2 + bx + c = 0
                                       or: bx + c = 0
     @param [in] a coefficient before x^2
     @param [in] b coefficient before x
     @param [in] c parameter in equation
     @param [out] x1 pointer to variable to assign first root
     @param [out] x2 pointer to variable to assign second root

     \return number of roots

     This function takes coefficients to solve square equation (or linear) and return number of roots in ascending order;
     If equation doesn't have solution then for roots will be assign NAN value
    */
    int solve ( const double a, const double b, const double c, double *x1, double *x2);


    /**
     \brief This function solves linear equasion: bx + c = 0

     @param [in] a coefficient before x^2
     @param [in] b coefficient before x
     @param [in] c parameter in equation
     @param [out] x1 pointer to variable to assign first root

     \return number of roots

     This function takes coefficients to solve linear equation and return number of roots;
     If equation doesn't have solution then for root will be assign NAN value
    */
    int solve_linear( const double b, const double c, double *x1);


    /**
     \brief This function solves equasion: ax^2 + bx + c = 0 (NB: a != 0 )

     @param [in] a coefficient before x^2
     @param [in] b coefficient before x
     @param [in] c parameter in equation
     @param [out] x1 pointer to variable to assign first root
     @param [out] x2 pointer to variable to assign second root

     \return number of roots

     This function takes coefficients to solve square equation (or linear) and return number of roots;
     If equation doesn't have solution then for roots will be assign NAN value
    */
    int solve_square( const double a, const double b, const double c, double *x1, double *x2);


    /**
     \brief This function shows solution to equasion: ax^2 + bx + c = 0
                                                  or: bx + c = 0
     @param [in] a coefficient before x^2
     @param [in] b coefficient before x
     @param [in] c parameter in equation
     @param [in] x1 pointer to variable to assign first root
     @param [in] x2 pointer to variable to assign second root

    */
    void show_result( const int number_of_roots, const double *x1, const double *x2);


      /**
    \brief This function gets coefficients for
           square equation: ax^2 + bx + c = 0 from console

    @param [out] a pointer to variable that contains coefficient before x^2
    @param [out] b pointer to variable that contains coefficient before x
    @param [out] c pointer to variable that contains parametre

    \return void

    */
    void get_coefficients(double *a, double *b, double *c);


    /**
    \brief This function gets one real number from console

    @param [out] n pointer to number, which would
                   contain value from console

    \return void

    This functions assign real number from console,
    if input is not a number, then function would ask for
    real number again

    */
    void get(double *n);

#endif
