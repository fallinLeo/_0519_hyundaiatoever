// 게임 보드 전체 상태 및 블록 위치 삽입/이동 관련
#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "blocks.h"
#include "cell.h"         //cell_t 
#include "console.h"      //windows_console_t

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_block(cell_t board[BOARD_H EIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);
void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir);
void board_roate_block(block_t* block);
void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);

#endif