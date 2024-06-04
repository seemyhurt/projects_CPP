﻿// multshap.cpp
// геометрические фигуры
#include "msoftcon.h"
///////////////////////////////////////////////////////////
class shape // базовый класс
{
protected:
    int xCo, yCo;     // координаты фигуры
    color fillcolor;  // цвет
    fstyle fillstyle; // стиль изображения
public:
    // конструктор без аргументов
    shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL)
    { }
    // конструктор с пятью аргументами
    shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs)
    { }
    // функция установки цвета и стиля
    void draw() const
    {
        set_color(fillcolor);
        set_fill_style(fillstyle);
    }
};
///////////////////////////////////////////////////////////
class circle : public shape
{
private:
    int radius; // радиус, а xCo и yCo будут координатами центра
public:
    // конструктор без параметров
    circle() : shape()
    { }
    // конструктор с пятью параметрами
    circle(int x, int y, int r, color fc, fstyle fs) : shape(x, y, fc, fs), radius(r)
    { }
    // функция рисования окружности
    void draw() const
    {
        shape::draw();
        draw_circle(xCo, yCo, radius);
    }
};
///////////////////////////////////////////////////////////
class rect : public shape
{
private:
    int width, height; // ширина и высота, а xCo и yCo будут координатами верхнего правого угла
public:
    // конструктор без параметров
    rect() : shape(), height(0), width(0)
    { }
    // конструктор с шестью параметрами
    rect(int x, int y, int h, int w, color fc, fstyle fs) : shape(x, y, fc, fs), height(h), width(w)
    { }
    // функция рисования прямоугольника
    void draw() const
    {
        shape::draw();
        draw_rectangle(xCo, yCo, xCo + width, yCo + height);
        // нарисуем диагональ
        set_color(cWHITE);
        draw_line(xCo, yCo, xCo + width, yCo + height);
    }
};
///////////////////////////////////////////////////////////
class tria : public shape
{
private:
    int height; // высота пирамиды, а xCo и yCo будут координатами вершины
public:
    // конструктор без параметров
    tria() : shape(), height(0)
    { }
    // конструктор с пятью параметрами
    tria(int x, int y, int h, color fc, fstyle fs) : shape(x, y, fc, fs), height(h)
    { }
    // функция рисования пирамиды
    void draw() const
    {
        shape::draw();
        draw_pyramid(xCo, yCo, height);
    }
};
///////////////////////////////////////////////////////////
int main()
{
    init_graphics(); // инициализируем систему отображения графики

    circle cir(40, 12, 5, cBLUE, X_FILL);      // создаем круг
    rect rec(12, 7, 10, 15, cRED, SOLID_FILL); // создаем прямоугольник
    tria tri(60, 7, 11, cGREEN, MEDIUM_FILL);  // создаем пирамиду

    // рисуем все наши фигуры
    cir.draw();
    rec.draw();
    tri.draw();

    set_cursor_pos(1, 25); // переводим курсор в самый низ экрана
    return 0;
}
