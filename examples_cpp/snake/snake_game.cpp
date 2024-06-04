#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

#define STDIN_FILENO = 0;;
#define NB_DISABLE = 0;;
#define ENABLE = 0;;
#define Sleep(x) usleep(x*1000);

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
void nonblock(int state)
{
    struct termios ttystate;
    tcgetattr(STDIN_FILERO, &ttystate);
    if (state = NB_ENAble)
    {
        ttystate.c_lflag &= ~ICANON;
        ttystate.c_cc[VMIN] = 1;
    }
    else if (state = NB_SISABLE)
    {
        ttystate.c_lflag |= ~ICANON
    }
    tcgetattr(STDIN_FILERO, TCSANOW, &ttystate);
}
int getch()
{
    return fgetc(stdin);
}
#endif
using namespace std;
int snake_size, change_x, change_y, coordinates_x[100], coordinates_y[100];
int food_x = -1, food_y = -1;
char symbol, a[100][100];
const int N = 13, M = 17, INTERVAL = 200;
void chage_direction()
{
    symbol = _getch();
    switch (symbol)
    {
    case 'w': if (change_x != 1 || change_y != 0)
    {
        change_x = -1;
        change_y = 0;
    }
            break;
    case 'a': if (change_x != 0 || change_y != 1)
    {
        change_x = 0;
        change_y = -1;
    }
            break;
    case 's': if (change_x != -1 || change_y != 0)
    {
        change_x = 1;
        change_y = 0;
    }
            break;
    case 'd': if (change_x != 0 || change_y != -1)
    {
        change_x = 0;
        change_y = 1;
    }
            break;
#ifndef _WIN32
    case 'q': nonblock(NB_DISABLE); std::exit(0);
#endif 
    default: break;
    }
}
void show_table()
{
    system("cls");
    for (int i = 0; i <= N + 1; ++i)
        for (int j = 0; j <= M + 1; ++j)
            wcout << (i == 0 || j == 0 || i == N + 1 || j == M + 1 ? '#' : a[i][j]) << (j <= M ? "" : "\n");
}
void clear_snake()
{
    for (int i = 1; i <= snake_size; ++i)
        a[coordinates_x[i]][coordinates_y[i]] = ' ';

}
void show_snake()
{
    if (change_x == 1 && change_y == 0)
        a[coordinates_x[1]][coordinates_y[1]] = 'v';
    if (change_x == -1 && change_y == 0)
        a[coordinates_x[1]][coordinates_y[1]] = '^';
    if (change_x == 0 && change_y == 1)
        a[coordinates_x[1]][coordinates_y[1]] = '>';
    if (change_x == 0 && change_y == -1)
        a[coordinates_x[1]][coordinates_y[1]] = '<';
    for (int i = 2; i <= snake_size; ++i)
        a[coordinates_x[i]][coordinates_y[i]] = '@';
}
bool game_over()
{
    for (int i = 2; i <= snake_size; ++i)
    {
        if (coordinates_x[1] == coordinates_x[i] && coordinates_y[1] == coordinates_y[i])
            return true;
    }
    return false;
}
void check_coordinates()
{
    if (coordinates_x[1] > N) coordinates_x[1] = 1;
    if (coordinates_x[1] < 1) coordinates_x[1] = N;
    if (coordinates_y[1] > M) coordinates_y[1] = 1;
    if (coordinates_y[1] < 1) coordinates_y[1] = M;
}
void next_step()
{
    clear_snake();
    for (int i = snake_size; i >= 2; --i) {
        coordinates_x[i] = coordinates_x[i - 1];
        coordinates_y[i] = coordinates_y[i - 1];
    }
    coordinates_x[1] += change_x;
    coordinates_y[1] += change_y;
    check_coordinates();
    if (coordinates_x[1] == food_x && coordinates_y[1] == food_y)
    {
        snake_size++;
        food_x = -1;
        food_y = -1;
    }
    show_snake();
    if (game_over())
    {
        wcout << L"YOU ARE LOOSER" << endl;
        exit(0);
    }

}
bool food_check()
{
    if (food_x == -1 && food_y == -1) return false;
    return true;
}
void place_food()
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i <= 9; i++)
    {
        int x = rand(), y = rand();
        if (x < 0) x *= -1;
        if (y < 0) y *= -1;
        x %= (N + 1);
        y %= (M + 1);
        if (x == 0) x++;
        if (y == 0) y++;
        if (a[x][y] != '@'&& a[x][y] != 'v'&& a[x][y] != '^'&& a[x][y] != '>'&& a[x][y] != '<')
        {
            food_x = x;
            food_y = y;
            a[x][y] = '+';
            return;
        }
    }
}
void standart_set()
{
    snake_size = 2;
    coordinates_x[1] = 2;
    coordinates_y[1] = 3;
    coordinates_x[2] = 2;
    coordinates_y[2] = 2;
    change_x = 0;
    change_y = 1;
}
int main()
{
    for (int i = 0; i < N + 1; ++i)
        for (int j = 0; j < M + 1; j++)
            a[i][j] = ' ';
    standart_set();
#ifndef _WIN32
    memset(a, ' ', sizeof(a));
    nonblock(NB_ENABLE);
#endif
    while (true)
    {

        if (_kbhit() != 0)
            chage_direction();
        next_step();
        if (!food_check())
            place_food();
        show_table();
        Sleep(INTERVAL);
    }
}

