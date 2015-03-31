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
#define ON       1
#define OFF      0
#define TRUE     1
#define FALSE    0
#define SEQLEN  12
/* ============ Definations end ============ */

/* ============ Variables start ============ */
int BASIC          = OFF;
int EDUCATION      = OFF;
int WORKEXPERIENCE = OFF;
int PROJECTS       = OFF;
int SKILLS         = OFF;
int MAIL           = OFF;
int HOMEPAGE       = OFF;
int LINKS          = OFF;
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
int getOption(char *opt);
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

int
getOption(char *opt)
{
    extern int BASIC, WEBSTACK;

    while ('\0' != *opt)
    {
        switch (*opt++)
        {
            case 'b': BASIC          = ON; break; 
            case 'e': EDUCATION      = ON; break;
            case 'w': WORKEXPERIENCE = ON; break;
            case 'p': PROJECTS       = ON; break;
            case 's': SKILLS         = ON; break;
            case 'm': MAIL           = ON; break;
            case 'h': HOMEPAGE       = ON; break;
            case 'l': LINKS          = ON; break;
            default: break;
        }
    }
}
/* ============ Functions implementations end ============ */

/* ============ Functions jump table starts ============ */
int (*cvSlice[])(void) = { basic, education, workexperience, projects, skills, mail, homepage, links };
/* ============ Functions jump table ends ============ */

#endif /* YOUNGLEE_H */
