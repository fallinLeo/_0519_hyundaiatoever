// cell.c
#include "cell.h"
#include <stdio.h>
#include "console.h"

void cell_init(cell_t* cell, int x, int y, cell_attributes_t att, color_t color) {
    cell->point.x = x;
    cell->point.y = y;
    cell->att = att;
    cell->color = color;
}

void cell_draw(cell_t* cell, uint32_t x, uint32_t y) {
    cell->point.x = x;
    cell->point.y = y;

    COORD pos;
    pos.X = (short)(cell->point.x * 2);
    pos.Y = (short)(cell->point.y);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
    printf("¡á");
}

void cell_draw_test(windows_console_t* console) {
    cell_t my_cell;
    cell_init(&my_cell, 0, 0, N, YELLOW);
    console_set_fore_color(console, my_cell.color);

    cell_draw(&my_cell, 0, 0); // ÁÂ»ó´Ü
    cell_draw(&my_cell, RESIZE_COLS / 2 - 1, 0); // ¿ì»ó´Ü
    cell_draw(&my_cell, RESIZE_COLS / 2 - 1, RESIZE_ROWS - 1); // ¿ìÇÏ´Ü
    cell_draw(&my_cell, 0, RESIZE_ROWS - 1); // ÁÂÇÏ´Ü
    cell_draw(&my_cell, (RESIZE_COLS / 2 - 1) / 2, (RESIZE_ROWS - 1) / 2); // Áß¾Ó
}
