#ifndef USEFULL_FUNCTIONS
#define USEFULL_FUNCTIONS

// compare double
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
@param [in] a  first variable to compare
@param [in] b  second variable
\return result of comparison

*/
int compare_double( const double a, const double b );


//clear buffer

/**
\brief This function clears buffer

This function clears buffer untill it meets '\n' symbol
*/
void clear_buffer();

//custom assert
#define Assert_Custom(condition)                                                \
if ( !(condition) )                                                             \
printf("Error ocured in expression %s, in Function %s (file %s in line %d)\n",  \
                             #condition, __PRETTY_FUNCTION__, __FILE__, __LINE__ );

#endif
