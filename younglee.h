#ifndef YOUNGLEE_H
#define YOUNGLEE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int basicInfo(void);
int showDetails(int intArgc, char *argv[]);

int basicInfo(void)
{
    printf("Young Lee\n");
    printf("\tyoungleemails@gmail.com\n");
    
    return TRUE;
}

int showDetails(int intArgc, char *charArgv[])
{
    /* TODO:  */
    return TRUE;
}

#endif /* YOUNGLEE_H */
