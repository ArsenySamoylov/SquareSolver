#ifndef COMPARE_DOUBLE
    #define COMPARE_DOUBLE


    const double EPSILON = 1e-6;

    enum COMPARE
         {
         FIRST_BIGGER,
         SAME,
         FIRST_LOWER,
         ERROR_COMPARISON
         };

    /**
    \brief Tis function compare two double's variables
    @param [in] a a first variable to compare
    @param [in] b b second variable
    \return resul of comparison

    */
    int compare_double( const double a, const double b );

#endif
