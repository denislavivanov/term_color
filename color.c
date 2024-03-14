#ifdef _WIN32
#include <Windows.h>

    struct Term
    {
        DWORD  dwOrigMode;
        HANDLE hConsole;
    } static s_TermState;

    void InitTerm(void)
    {
        DWORD dwMode;

        s_TermState.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleMode(s_TermState.hConsole, &dwMode);

        s_TermState.dwOrigMode = dwMode;
        dwMode                |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(s_TermState.hConsole, dwMode);
    }

    void RestoreTerm(void)
    {
        SetConsoleMode(s_TermState.hConsole, s_TermState.dwOrigMode);
    }
#endif
