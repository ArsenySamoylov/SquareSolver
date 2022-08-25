#ifndef SOLVE_AND_SHOW_H_INCLUDED
#define SOLVE_AND_SHOW_H_INCLUDED


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
     @param [in] a a coefficient before x^2
     @param [in] b b coefficient before x
     @param [in] c c parametre
     @param [out] x1 pointer to variable to assign first root
     @param [out] x2 pointer to variable to assign second root

     \return number of roots

     This function takes coefficients to solve square equation (or linear) and return number of roots;
     If equation doesn't have solution then for roots will be assign NAN value
    */
    int solve ( const double a, const double b, const double c, double *x1, double *x2);


    /**
     \brief This function solves linear equasion: bx + c = 0

     @param [in] a a coefficient before x^2
     @param [in] b b coefficient before x
     @param [in] c c parametre
     @param [out] x1 pointer to variable to assign first root

     \return number of roots

     This function takes coefficients to solve linear equation and return number of roots;
     If equation doesn't have solution then for root will be assign NAN value
    */
    int solve_linear( const double b, const double c, double *x1);


    /**
     \brief This function solves equasion: ax^2 + bx + c = 0 (NB: a != 0 )

     @param [in] a a coefficient before x^2
     @param [in] b b coefficient before x
     @param [in] c c parametre
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
     @param [in] a a coefficient before x^2
     @param [in] b b coefficient before x
     @param [in] c c parametre
     @param [in] x1 pointer to variable to assign first root
     @param [in] x2 pointer to variable to assign second root

    */
    void show_result( const int number_of_roots, const double *x1, const double *x2);



    #include "get_coefficients.h"

#endif
