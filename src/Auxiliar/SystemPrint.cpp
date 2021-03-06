#include "Auxiliar/SystemPrint.h"
#include <iostream>

void SystemPrint::clear_line() {
    for (int i = 0; i < 80; i++) {
        std::cout << ' ';
    }
    std::cout << '\r';
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

#include <windows.h>

void SystemPrint::reset_cursor() {
    COORD tl = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, tl);
}

void SystemPrint::clear_screen() {
    COORD tl = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO s;
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

#else

void SystemPrint::reset_cursor() {
    for (int i = 0; i < 50; i++) {
        std::cout << std::endl;
    }
}

void SystemPrint::clear_screen() {
    for (int i = 0; i < 50; i++) {
        std::cout << std::endl;
    }
}

#endif