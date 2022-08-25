 #ifndef GET_COEFFICIENTS_H
 #define GET_COEFFICIENTS_H

    /**
    \brief This function gets coefficients for
           square equation: ax^2 + bx + c = 0 from console

    @param [out] a a, pointer to variable that contains coefficient before x^2
    @param [out] b b, pointer to variable that contains coefficient before x
    @param [out] c c, pointer to variable that contains parametre

    \return void

    */
    void get_coefficients(double *a, double *b, double *c);

    /**
    \brief This function gets one real number from console

    @param [out] n n pointer to number, which would
                   contain value from console

    \return void

    This functions assign real number from console,
    if input is not a number, then function would ask for
    real number again

    */
    void get(double *n);


#endif
