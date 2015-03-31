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
    {
        if (1 == argc) {
            char *dft = "x";
            getOption(dft);
            break;
        }
        if (*argv[iter] == '-')
            getOption(argv[iter] + 1);
    }
    
    getCVItems(top, cvSlice);
    
    return 0;
}
