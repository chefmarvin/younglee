#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ncurses.h>
#include <signal.h>
#include <unistd.h>

#include "younglee.h"
#include "view.h"

int main(int argc, char *argv[])
{
    int iter;
    int col, row, height, width, key, highlight = 0, choice = 0, marginTop = 0, marginRight = 0, marginBottom = 0, marginLeft = 0;
    WINDOW *panel_win;
    WINDOW *menu_win;
    WINDOW *content_win;

#ifdef OPTIONS
    for (iter = 0; iter < argc; iter++)
    {
        if (1 == argc) {
            char *dft = "x";
            getOption(dft);
            break;
        } else
            if (*argv[iter] == '-')
                getOption(argv[iter] + 1);
    }
#endif // OPTIONS

    initscr();
    clear();
    noecho();
    cbreak();
    getmaxyx(stdscr, row, col);
    marginTop  = marginBottom =  (row * 0.1) / 2;
    marginLeft = marginRight = (col * 0.1) / 2;
    height     = row * 0.9;
    width      = col * 0.9;

    if (row < 18 && col < 40) {
        mvwprintw(stdscr, row / 2 - 1, col > 20 ? col / 2 - 11 : 0, "No enough screen space.");
        mvwprintw(stdscr, row / 2 + 1, col > 20 ? col / 2 - 13 : 0, "Try \'man younglee\' instead.");
        wrefresh(stdscr);
    } else {
        panel_win = newwin(height, width, marginTop, marginLeft);
        menu_win = newwin(height - 4, 20, marginTop + PADDING_TOP, marginLeft + 1);
        content_win = newwin(height - 4, width - 22, marginTop + PADDING_TOP, marginLeft + 21);
        keypad(menu_win, TRUE);
        mvprintw(0, 1, "Use arrow keys to navigate, Press enter to select a choice.");
        mvwprintw(panel_win, 1, 4, "Young Lee's CV");
        refresh();
        drawBox(panel_win, highlight);
        drawMenu(menu_win, highlight, choice);
        drawBox(content_win, highlight);

        getCVItems(choice, cvSlice, content_win);        
        
        while (1) {
            key = wgetch(menu_win);
            switch (key) {
                case KEY_UP:    /* Scroll up */
                    if (0 == highlight) {
                        highlight = nItems - 1;
                    } else {
                        highlight--;
                    }
                    break;
                case KEY_DOWN:    /* Scroll down */
                    if (nItems - 1 == highlight) {
                        highlight = 0;
                    } else {
                        highlight++;
                    }
                    break;
                case 10:    // Enter
                    choice = highlight;
                    break;
                default:
                    /* TODO:  */                    
                    continue;
                    break;
            }
            if (IDX_EXIT == choice)
                break;
            
            wclear(content_win);
            getCVItems(choice, cvSlice, content_win);
            drawBox(panel_win, highlight);
            drawMenu(menu_win, highlight, choice);
            drawBox(content_win, highlight);
        }
    }

    endwin();
    
    return 0;
}
