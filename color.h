#ifndef TERM_COLOR_H
#define TERM_COLOR_H

#define BLACK      30
#define RED        31
#define GREEN      32
#define YELLOW     33
#define BLUE       34
#define MAGENTA    35
#define CYAN       36
#define WHITE      37

#define BR_BLACK   90
#define BR_RED     91
#define BR_GREEN   92
#define BR_YELLOW  93
#define BR_BLUE    94
#define BR_MAGENTA 95
#define BR_CYAN    96
#define BR_WHITE   97

#define cprintfex(fg, bg, fmt, ...) \
        printf("\x1B[1;%d;%dm" fmt "\x1B[0m", fg, bg+10, ##__VA_ARGS__)

#define cprintf(fg, fmt, ...) \
        printf("\x1B[1;%dm" fmt "\x1B[0m", fg, ##__VA_ARGS__)

#ifdef _WIN32
    void InitTerm(void);
    void RestoreTerm(void);
#endif
#endif
