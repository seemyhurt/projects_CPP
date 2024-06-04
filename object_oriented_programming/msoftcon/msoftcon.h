//msoftcon.h
//ќбъ€влени€ функций консольной графики от Lafore
//используютс€ консольные функции Windows 

#ifndef _INC_WCONSOLE    //этот файл не должен включатьс€
#define _INC_WCONSOLE    //дважды в тот же исходный файл

#include <windows.h>     //дл€ консольных функций Windows
#include <conio.h>       //дл€ kbhit(), getche()

enum fstyle {
    SOLID_FILL, X_FILL, O_FILL,
    LIGHT_FILL, MEDIUM_FILL, DARK_FILL
};

enum color {
    cBLACK = 0, cDARK_BLUE = 1, cDARK_GREEN = 2, DARK_CYAN = 3,
    cDARK_RED = 4, cDARK_MAGENTA = 5, cBROWN = 6, cLIGHT_GRAY = 7,
    cDARK_GRAY = 8, cBLUE = 9, cGREEN = 10, cCYAN = 11,
    cRED = 12, cMAGENTA = 13, cYELLOW = 14, cWHITE = 15
};
//---------------------------------------------------------
void __declspec(dllexport) init_graphics();
void __declspec(dllexport) set_color(color fg, color bg = cBLACK);
void __declspec(dllexport) set_cursor_pos(int x, int y);
void __declspec(dllexport) clear_screen();
void __declspec(dllexport) wait(int milliseconds);
void __declspec(dllexport) clear_line();
void __declspec(dllexport) draw_rectangle(int left, int top, int right, int bottom);
void __declspec(dllexport) draw_circle(int x, int y, int rad);
void __declspec(dllexport) draw_line(int x1, int y1, int x2, int y2);
void __declspec(dllexport) draw_pyramid(int x1, int y1, int height);
void __declspec(dllexport) set_fill_style(fstyle);

#endif /* _INC_WCONSOLE */
