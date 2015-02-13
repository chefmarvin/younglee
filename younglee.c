#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "younglee.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    switch(argc)
    {
        case 1:
            basicInfo();
            break;
        default:
            showDetails(argc, argv);
            break;
    }
    
    return 0;
}
