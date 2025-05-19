// cell.h
#pragma once
#ifndef __CELL_H__
#define __CELL_H__

#include <stdint.h>
#include "console.h" // point_t, color_t 필요

typedef enum _cell_attributes_t {
    E, // Empty
    W, // Wall
    N  // Normal (블럭 셀)
} cell_attributes_t;

typedef struct _cell_t {
    point_t point;
    color_t color;
    cell_attributes_t att;
} cell_t;

void cell_init(cell_t* cell, int x, int y, cell_attributes_t att, color_t color);
void cell_draw(cell_t* cell, uint32_t x, uint32_t y);
void cell_draw_test(windows_console_t* console); // optional: 테스트용

#endif // __CELL_H__

