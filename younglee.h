#ifndef YOUNGLEE_H
#define YOUNGLEE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>

#include "view.h"

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
#define IDX_EXIT           8
#define PADDING_TOP        2
#define PADDING_LEFT       2

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
char *items[] = { 
    "BASIC INFOMATION",
    "EDUCATION",
    "WORK EXPERIENCES",
    "PROJECTS",
    "SKILLS",
    "MAIL",
    /* "HOMEPAGE", */
    "LINKS",
    "EXIT",
};
int nItems = sizeof(items) / sizeof(char *);
/* ============ Variables end ============ */

/* ============ Functions prototypes start ============ */
int basic(WINDOW *win);
int education(WINDOW *win);
int workexperience(WINDOW *win);
int projects(WINDOW *win);
int skills(WINDOW *win);
int mail(WINDOW *win);
int homepage(WINDOW *win);
int links(WINDOW *win);
void getOption(char *opt);
int getCVItems(int idx, int (*cvStack[])(WINDOW *win), WINDOW *win);
void drawMenu(WINDOW *menuWin, int highlight, int choice);
void drawBox(WINDOW *boxWin, int highlight);
/* ============ Functions prototypes end ============ */

/* ============ Functions implementations start ============ */
int
basic(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, NAME);
    mvwprintw(win, 3, 1, DESCRIPTION1);
    mvwprintw(win, 5, 1, DESCRIPTION2);
    mvwprintw(win, 7, 1, DESCRIPTION4);
    /* mvwprintw(win, 9, 1, DESCRIPTION4); */
    mvwprintw(win, 9, 1, JOBDESCRIPTION);
    mvwprintw(win, 11, 1, TEL);
    mvwprintw(win, 13, 1, EMAIL);
    wattroff(win, A_BOLD);
    wrefresh(win);
    
    return TRUE;
}

int
education(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, SCHOOLSTR);
    mvwprintw(win, 2, 1, SCHOOL);
    mvwprintw(win, 3, 1, SCHOOLLINK);
    mvwprintw(win, 5, 1, MAJORSTR);
    mvwprintw(win, 6, 1, MAJOR);
    mvwprintw(win, 8, 1, TIME);
    mvwprintw(win, 9, 1, TIMERANGE);
    mvwprintw(win, 11, 1, DEGREESTR);
    mvwprintw(win, 12, 1, DEGREE);
    wattroff(win, A_BOLD);
    return TRUE;
}

int
workexperience(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, TONGJI);
    mvwprintw(win, 2, 1, TONGJITIME);
    mvwprintw(win, 3, 1, TONGJIDES1);
    mvwprintw(win, 4, 1, TONGJIDES2);
    mvwprintw(win, 5, 1, TONGJIDES3);
    mvwprintw(win, 6, 1, TONGJIDES4);
    mvwprintw(win, 8, 1, PAY);
    mvwprintw(win, 9, 1, PAYTIME);
    mvwprintw(win, 10, 1, PAYDES);
    mvwprintw(win, 12, 1, ACCOUNT);
    mvwprintw(win, 13, 1, ACCOUNTTIME);
    mvwprintw(win, 14, 1, ACCOUNTDES);
    wattroff(win, A_BOLD);
    return TRUE;
}

int
projects(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, JQUERYCART);
    mvwprintw(win, 2, 1, JQUERYCARTLINK);
    mvwprintw(win, 3, 1, JQUERYCARTDES);
    mvwprintw(win, 5, 1, SDN);
    mvwprintw(win, 6, 1, SDNDES1);
    mvwprintw(win, 7, 1, SDNDES2);
    mvwprintw(win, 8, 1, SDNDES3);
    wattroff(win, A_BOLD);
    return TRUE;
}

int
skills(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, WEBSTACK);
    mvwprintw(win, 2, 1, JS);
    mvwprintw(win, 3, 1, OOPJS);
    mvwprintw(win, 4, 1, JQ);
    mvwprintw(win, 5, 1, UNDERSCORE);
    mvwprintw(win, 6, 1, CSS);
    mvwprintw(win, 7, 1, CSSINFO);
    mvwprintw(win, 8, 1, HTML);
    mvwprintw(win, 9, 1, HTMLINFO);
    mvwprintw(win, 10, 1, SERVERSIDE);
    mvwprintw(win, 11, 1, SERVERSIDEINFO1);
    mvwprintw(win, 12, 1, SERVERSIDEINFO2);
    mvwprintw(win, 13, 1, TOOLS);
    mvwprintw(win, 14, 1, TOOLSINFO);
    mvwprintw(win, 15, 1, LANGUAGE);
    mvwprintw(win, 16, 1, LANGUAGEINFO1);
    mvwprintw(win, 17, 1, LANGUAGEINFO2);
    wattroff(win, A_BOLD);
    return TRUE;
}

int
mail(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, MAILSTR);
    mvwprintw(win, 2, 1, NETEASE);
    mvwprintw(win, 4, 1, TELSTR);
    mvwprintw(win, 5, 1, NUMBER);
    wattroff(win, A_BOLD);
    return TRUE;
}

int
homepage(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, "Homepage");
    wattroff(win, A_BOLD);
    
    return TRUE;
}

int
links(WINDOW *win)
{
    wattron(win, A_BOLD);
    mvwprintw(win, 1, 1, GITHUBSTR);
    mvwprintw(win, 2, 1, GITHUB);
    mvwprintw(win, 4, 1, DOUBANSTR);
    mvwprintw(win, 5, 1, DOUBAN);
    mvwprintw(win, 7, 1, LINKEDINSTR);
    mvwprintw(win, 8, 1, LINKEDIN);
    mvwprintw(win, 10, 1, ZHIHUSTR);
    mvwprintw(win, 11, 1, ZHIHU);
    
    wattroff(win, A_BOLD);
    return TRUE;
}

/* ============ Functions jump table starts ============ */
int (*cvSlice[CVITEMS])(WINDOW *win) = {
    basic,
    education,
    workexperience,
    projects,
    skills,
    mail,
    /* homepage, */
    links
};
/* ============ Functions jump table ends ============ */


#ifdef OPTIONS
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
                /* cvSlice[top++] = &basic; */
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
#endif // OPTIONS


int
getCVItems(int idx, int (*cvStack[])(WINDOW *win), WINDOW *win)
{
    int iter, FLAG = TRUE;

    mvwprintw(win, 1, 1, "%d", idx);

    FLAG = cvStack[idx](win);

    return FLAG;
}

void
drawMenu(WINDOW *menuWin, int highlight, int choice)
{
    int paddingTop = PADDING_TOP, paddingLeft = PADDING_LEFT, i;

    box(menuWin, 0, 0);
    for (i = 0; i < nItems; i++) {
        if (i == highlight) {
            if (i == choice) {
                wattron(menuWin, A_REVERSE | A_BOLD);
                mvwprintw(menuWin, paddingLeft, paddingTop, "%s", items[i]);
                wattroff(menuWin, A_REVERSE | A_BOLD);
            } else {
                wattron(menuWin, A_REVERSE);
                mvwprintw(menuWin, paddingLeft, paddingTop, "%s", items[i]);
                wattroff(menuWin, A_REVERSE);
            }
        } else {
            if (i == choice) {
                wattron(menuWin, A_BOLD);
                mvwprintw(menuWin, paddingLeft, paddingTop, "%s", items[i]);
                wattroff(menuWin, A_BOLD);
            } else {
                mvwprintw(menuWin, paddingLeft, paddingTop, "%s", items[i]);
            }
        }
        ++paddingLeft;
    }
    wrefresh(menuWin);
}

void
drawBox(WINDOW *boxWin, int highlight)
{
    box(boxWin, 0, 0);
    wrefresh(boxWin);
}

/* ============ Functions implementations end ============ */

#endif /* YOUNGLEE_H */
