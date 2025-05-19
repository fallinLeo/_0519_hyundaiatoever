// 테트리스 블록 정의 및 초기화 관련

#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
//#define MAX_BLOCK_COUNT 7

#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4
#define BLOCK_ROTATE_COUNT 4

/*
typedef enum _cell_attributes_t {
	E, // 비었음 empty
	W, // 벽, 없앨수 없음
	N, // 없앨수 있는 일반적인 셀
} cell_attributes_t;
*/

//"#define 블럭이화면오른쪽으로갈수있는최대값 100" 이 정의에서 블럭이화면오른쪽으로갈수있는최대값을 뭐라고 작명하면 좋을까?
// 블럭이 오른쪽으로 이동할수 있는 최대값은 단순히 120/2-1이 아니다!
// 블럭 좌상단이 기준점이 되기때문에 -3을 추가로 해줘야 한다.
#define MAX_BLOCK_X_POS ((DEFAULT_CONSOLE_ROWS/2-1)-(BLOCK_WIDTH-1))

// (이전에도 말했지만) y축으로는 /2 해줄 필요없다.
// A는 가로0.5, 세로 1의 비율이지만, ■는 1:1 비율이기 때문이다.
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
	COLOR_CYAN= 3,      // 하늘색
	COLOR_BLUE= 1,      // 파란색
	COLOR_ORANGE= 12,    // 주황색이 없어서..
	COLOR_YELLOW= 14,    // 노란색
	COLOR_GREEN= 2,     // 초록색
	COLOR_PURPLE= 5,    // 보라색
	COLOR_RED=4        // 빨간색
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
void block_rotate(block_t* block); // 주의! 회전만 시키고 그리지는 않는다.
void block_set_xy(block_t* block, uint32_t x, uint32_t y); // 역시, x,y값만 바뀌고 그리지는 않는다.

#endif