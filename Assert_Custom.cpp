#ifndef Asseert_Custom(condition)

    #define Assert_Custom(condition)                             \
        if ( !(condition) )                                      \
        printf("Error ocured in expression %s, (in line %d)\n",  \
                                    #condition,   __LINE__ );    \

#endif

// нужно проверить
