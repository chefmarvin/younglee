#ifndef YOUNGLEE_H
#define YOUNGLEE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>

/* ============ Definations start ============ */
#define CVITEMS           12
#define TRUE               1
#define FALSE              0
#define DFTFUN            -1
#define IDX_BASIC          0
#define IDX_EDUCATION      1
#define IDX_WORKEXPERIENCE 2
#define IDX_PROJECTS       3
#define IDX_SKILLS         4
#define IDX_MAIL           5
#define IDX_HOMEPAGE       6
#define IDX_LINKS          7

/* ============ Definations end ============ */

/* ============ Variables start ============ */
int top            = 0;
int BASIC          = DFTFUN;
int EDUCATION      = DFTFUN;
int WORKEXPERIENCE = DFTFUN;
int PROJECTS       = DFTFUN;
int SKILLS         = DFTFUN;
int MAIL           = DFTFUN;
int HOMEPAGE       = DFTFUN;
int LINKS          = DFTFUN;
wchar_t jchars[] = L"ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをんゔゕゖ゙゚゛゜ゝゞゟ゠ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヷヸヹヺーヽヾヿㇰㇱㇲㇳㇴㇵㇶㇷㇸㇹㇺㇻㇼㇽㇾㇿ";
/* ============ Variables end ============ */

/* ============ Functions prototypes start ============ */
int basic(void);
int education(void);
int workexperience(void);
int projects(void);
int skills(void);
int mail(void);
int homepage(void);
int links(void);
void getOption(char *opt);
int getCVItems(int itemNum, int (*cvStack[])(void));
/* ============ Functions prototypes end ============ */

/* ============ Functions implementations start ============ */
int
basic(void)
{
    printf("Basic: \n\t\n");
    return TRUE;
}

int
education()
{
    printf("Education: \n\t\n");
    return TRUE;
}

int
workexperience(void)
{
    printf("Work Experience: \n\t\n");
    return TRUE;
}

int
projects(void)
{
    printf("Projects: \n\t\n");
    return TRUE;
}

int
skills(void)
{
    printf("Skills: \n\t\n");
    return TRUE;
}

int
mail(void)
{
    printf("Mail: \n\t\n");
    return TRUE;
}

int
homepage(void)
{
    printf("Homepage: \n\t\n");
    return TRUE;
}

int
links(void)
{
    printf("Links: \n\t\n");
    return TRUE;
}

/* ============ Functions jump table starts ============ */
int (*cvSlice[CVITEMS])(void) = {};
/* ============ Functions jump table ends ============ */

void
getOption(char *opt)
{
    extern int BASIC, WEBSTACK, top;

    while ('\0' != *opt)
    {
        switch (*opt++)
        {
            case 'b':
                cvSlice[top++] = &basic;
                break;
            case 'e':
                cvSlice[top++] = &education;
                break;
            case 'w':
                cvSlice[top++] = &workexperience;
                break;
            case 'p':
                cvSlice[top++] = &projects;
                break;
            case 's':
                cvSlice[top++] = &skills;
                break;
            case 'm':
                cvSlice[top++] = &mail;
                break;
            case 'h':
                cvSlice[top++] = &homepage;
                break;
            case 'l':
                cvSlice[top++] = &links;
                break;
            default:
                cvSlice[top++] = &basic;
                cvSlice[top++] = &education;
                cvSlice[top++] = &workexperience;
                cvSlice[top++] = &projects;
                cvSlice[top++] = &skills;
                cvSlice[top++] = &mail;
                cvSlice[top++] = &homepage;
                cvSlice[top++] = &links;
                break;
        }
    }
}

int
getCVItems(int itemNum, int (*cvStack[])(void))
{
    int iter, FLAG = TRUE;
    for (iter = 0; iter < itemNum; iter++) {
        FLAG = cvStack[iter]();
        if (FALSE == FLAG)
            break;
    }
}
/* ============ Functions implementations end ============ */


#endif /* YOUNGLEE_H */
