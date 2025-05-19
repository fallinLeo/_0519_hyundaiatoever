// ��Ʈ���� ��� ���� �� �ʱ�ȭ ����

#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
//#define MAX_BLOCK_COUNT 7

#include "console.h"

#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4
#define BLOCK_ROTATE_COUNT 4

/*
typedef enum _cell_attributes_t {
	E, // ����� empty
	W, // ��, ���ټ� ����
	N, // ���ټ� �ִ� �Ϲ����� ��
} cell_attributes_t;
*/

//"#define ����ȭ����������ΰ����ִ��ִ밪 100" �� ���ǿ��� ����ȭ����������ΰ����ִ��ִ밪�� ����� �۸��ϸ� ������?
// ���� ���������� �̵��Ҽ� �ִ� �ִ밪�� �ܼ��� 120/2-1�� �ƴϴ�!
// �� �»���� �������� �Ǳ⶧���� -3�� �߰��� ����� �Ѵ�.
#define MAX_BLOCK_X_POS ((DEFAULT_CONSOLE_ROWS/2-1)-(BLOCK_WIDTH-1))

// (�������� ��������) y�����δ� /2 ���� �ʿ����.
// A�� ����0.5, ���� 1�� ����������, ��� 1:1 �����̱� �����̴�.
#define MAX_BLOCK_Y_POS ((DEFAULT_CONSOLE_COLS-1)-(BLOCK_HEIGHT-1))

typedef enum _block_shapes_t {
	BLOCK_I,
	BLOCK_J,
	BLOCK_L,
	BLOCK_O,
	BLOCK_S,
	BLOCK_T,
	BLOCK_Z,
	BLOCK_MAX
} block_shapes_t;

typedef enum _block_color_t {
	COLOR_CYAN= 3,      // �ϴû�
	COLOR_BLUE= 1,      // �Ķ���
	COLOR_ORANGE= 12,    // ��Ȳ���� ���..
	COLOR_YELLOW= 14,    // �����
	COLOR_GREEN= 2,     // �ʷϻ�
	COLOR_PURPLE= 5,    // �����
	COLOR_RED=4        // ������
} block_color_t;


typedef struct _block_t {
	block_shapes_t shape;
	int rotation_index;
	uint8_t att[BLOCK_ROTATE_COUNT][BLOCK_HEIGHT][BLOCK_WIDTH];
	int x;
	int y;
	block_color_t color;
} block_t;

#define DEFAULT_CONSOLE_ROWS 120
#define DEFAULT_CONSOLE_COLS 30

char* get_block_string(block_shapes_t shape);
void block_init(block_t* block, block_shapes_t shape);
void block_display_info(const block_t* blk, bool option);
void block_rotate(block_t* block); // ����! ȸ���� ��Ű�� �׸����� �ʴ´�.
void block_set_xy(block_t* block, uint32_t x, uint32_t y); // ����, x,y���� �ٲ�� �׸����� �ʴ´�.
void block_draw(block_t* block);

#endif