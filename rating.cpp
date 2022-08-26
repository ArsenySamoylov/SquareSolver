
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_reward();

void rate()
    {
    printf("Rate our programm from 1 to 5\n(if you want a secrete prise -> rate 5 ;) - ") ;
    int r;
    scanf("%d", &r);
    printf("\nOur  rating: %d *****\n", r);
    if( r == 5)
       print_reward();
    }



    // developing
void print_reward()
    {
    printf("\n");
    printf("MEOWOOOOO MEOWwwwww \n");
    printf(" ,_     _           \n");
    printf(" |\\\\_,-~/           \n");
    printf(" / _  _ |    ,--.   \n");
    printf("(  @  @ )   / ,-'   \n");
    printf(" \\  _T_/-._( (      \n");
    printf(" /         `. \\     \n");
    printf("|         _  \\ |    \n");
    printf(" \\ \\ ,  /      |    \n");
    printf("  || |-_\\__   /     \n");
    printf(" ((_/`(____,-'      \n");
getchar();
    }
