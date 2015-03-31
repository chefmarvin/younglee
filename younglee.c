#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>

#include "younglee.h"

int main(int argc, char *argv[])
{
    int iter;
    for (iter = 0; iter < argc; iter++)
        if (*argv[iter] == '-')
            getOption(argv[iter] + 1);

    cvSlice[1]();
    
    /* switch(argc) */
    /* { */
    /*     case 1: */
    /*         basic(); */
    /*         break; */
    /*     default: */
    /*         basic(); */
    /*         education(); */
    /*         break; */
    /* } */
    
    return 0;
}
