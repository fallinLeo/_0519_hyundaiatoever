// ���� ���� ��ü ���� �� ��� ��ġ ����/�̵� ����
#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "blocks.h"
#include "cell.h"         //cell_t 
#include "console.h"      //windows_console_t

// ----------------------------------
// ��Ʈ������ ǥ������ ���� �ʵ� ũ��� ���� 10���, ���� 20����Դϴ�.
#define BOARD_WIDTH 10 + 2 // 2�� �þ���� ���� ������ Wall Cell�̴�.
#define BOARD_HEIGHT 20 + 1 // 1�� �þ���� ���� ���������� Bottom Cell

#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

#define BOARD_START_X (4)
#define BOARD_START_Y (4)
// ��          �� // (0,0),(1,0),(2,0),(n,0), ...
// ��          �� // (0,1),
// ��          �� // (0,2),
// .............. 
// �������� // (0,n),

// ��ü ���� ���� ����
extern cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH];
// ���� �ʱ� ������ ���� �ִ� ������
extern cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH];

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);
void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir);
void board_roate_block(block_t* block);
void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);

#endif