#include <string.h>

#include "blocks.h"

// 모든 테트리스 블럭의 모양은 I, J, L, O, S, T, Z 
// Total Blocks Shapes is I, J, L, O, S, T, Z

/*
1. block I
cyan 하늘색
□■□□  □□□□  □□■□  □□□□
□■□□  ■■■■  □□■□  □□□□
□■□□  □□□□  □□■□  ■■■■
□■□□  □□□□  □□■□  □□□□
*/
const uint8_t data_i[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 2 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 2, 0},
		{ 0, 0, 2, 0},
		{ 0, 0, 2, 0},
		{ 0, 0, 2, 0}
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 2 },
		{ 0, 0, 0, 0 },
	}
};

/*
2. block J
Blue 파란색

□■□□  ■□□□  □■■□  □□□□
□■□□  ■■■□  □■□□  ■■■□
■■□□  □□□□  □■□□  □□■□
□□□□  □□□□  □□□□  □□□□
*/
const uint8_t data_j[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 0, 0, 0 },
		{ 2, 2, 2, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 2, 2, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 0 },
		{ 0, 0, 2, 0 },
		{ 0, 0, 0, 0 }
	},
};

/*
3. block L
Orange 오렌지, 주황색

□■□□  □□□□  ■■□□  □□■□
□■□□  ■■■□  □■□□  ■■■□
□■■□  ■□□□  □■□□  □□□□
□□□□  □□□□  □□□□  □□□□
*/

const uint8_t data_l[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 0 },
		{ 2, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 2, 0 },
		{ 2, 2, 2, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
};


/*
4. block O
Yellow, 노란색
■■□□  ■■□□  ■■□□  ■■□□
■■□□  ■■□□  ■■□□  ■■□□
□□□□  □□□□  □□□□  □□□□
□□□□  □□□□  □□□□  □□□□
*/

const uint8_t data_o[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 2, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};

/*
5. block S
Green 녹색
□■■□  ■□□□  □■■□  □■□□
■■□□  ■■□□  ■■□□  □■■□
□□□□  □■□□  □□□□  □□■□
□□□□  □□□□  □□□□  □□□□
*/

const uint8_t data_s[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 2, 2, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 0, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 2, 2, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 2, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 2, 0 },
		{ 0, 0, 0, 0 }
	},
};

/*
6. block T
Violet 보라색
□■□□  □■□□  ■■■□  □■□□
■■■□  ■■□□  □■□□  □■■□
□□□□  □■□□  □□□□  □■□□
□□□□  □□□□  □□□□  □□□□
*/
const uint8_t data_t[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 2, 0, 0 },
		{ 2, 2, 2, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 2, 2, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 2, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
/*
7. block Z
Red 빨간색

■■□□  □■□□  ■■□□  □□■□
□■■□  ■■□□  □■■□  □■■□
□□□□  ■□□□  □□□□  □■□□
□□□□  □□□□  □□□□  □□□□
*/
const uint8_t data_z[BLOCK_ROTATE_COUNT][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 2, 2, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 2, 0, 0 },
		{ 2, 2, 0, 0 },
		{ 2, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 2, 2, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 2, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 0, 0, 0 }
	},
};


// 블록 초기화 함수
void block_init(block_t* block, block_shapes_t shape) {
    block->shape = shape;

    switch (shape) {
    case BLOCK_I:
        block->color = COLOR_CYAN;
        memcpy(block->att, data_i, sizeof(data_i));
        break;
    case BLOCK_J:
        block->color = COLOR_BLUE;
        memcpy(block->att, data_j, sizeof(data_j));
        break;
    case BLOCK_L:
        block->color = COLOR_ORANGE;
        memcpy(block->att, data_l, sizeof(data_l));
        break;
    case BLOCK_O:
        block->color = COLOR_YELLOW;
        memcpy(block->att, data_o, sizeof(data_o));
        break;
    case BLOCK_S:
        block->color = COLOR_GREEN;
        memcpy(block->att, data_s, sizeof(data_s));
        break;
    case BLOCK_T:
        block->color = COLOR_PURPLE;
        memcpy(block->att, data_t, sizeof(data_t));
        break;
    case BLOCK_Z:
        block->color = COLOR_RED;
        memcpy(block->att, data_z, sizeof(data_z));
        break;
    default:
        break;
    }

    // 초기 위치 및 회전 설정
    block->x = 0;             // 기본 X 위치
    block->y = 0;             // 기본 Y 위치
    block->rotation_index = 0; // 기본 회전 상태 (0)
}



//printf("Block Shape: %d\n", get_block_string(block_1.shape));
//printf("Block Color: %d\n", get_block_color(block_1.color));

//I, J, L, O, S, T, Z

const char* block_string[BLOCK_MAX] = {
	"I",
	"J",
	"L",
	"O",
	"S",
	"T",
	"Z"
};

char* get_block_string(block_shapes_t shape) {
	if (shape >= 0 && shape < BLOCK_MAX) { // 유효한 범위인지 확인
		return block_string[shape];       // 해당 블록 이름 반환
	}
	return "Unknown"; // 유효하지 않은 값이면 기본값 반환
}


void block_display_info(const block_t* blk, bool option) {
	//printf("Block Shape: %s\n", get_block_string(blk->shape));
	////printf("Block Color: %s\n", get_color_string(blk->color));
	//printf("Block Color: %d\n", blk->color);
	//printf("Block Rotation (%d):\n", blk->rotation_index);

	static uint32_t dummy_cnt = 0;
	printf("[%d] Block (shape,r_idx,x,y,color)=(%s,%d,%d,%d,%d)\r\n", \
		++dummy_cnt, get_block_string(blk->shape), blk->rotation_index, blk->x, blk->y, blk->color \
	);

	if(option==true) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				printf("%d ", blk->att[blk->rotation_index][i][j]);
			}
			printf("\r\n");
		}
	}
	printf("\r\n");
}


//block_Z.rotation_index += 1;
//block_Z.rotation_index %= 4;
//block_rotate(&block_Z); // 함수를 만들자. 시계방향으로 도나? 반시계로 도나?
void block_rotate(block_t* block) { // 회전만 시키고 그리지는 않는다.
	block->rotation_index += 1;
	block->rotation_index %= 4;
}
//회전후 그릴 경우 block_draw() 함수를 호출해야 한다.
//block_draw(&block_Z, block_Z.x, block_Z.y);


//block_Z.x -= 1;            
//block_draw(&block_Z, block_Z.x, block_Z.y);
//block_set_pos(&block, block_Z.x - 1, block_Z.y);

// 블럭을 x,y 좌표로 이동시킨다.
// block 내부의 멤버변수 x,y만 수정될뿐이지 새로 그리지는 않는다.
// 새로 그리고 싶다면 block_draw() 함수를 호출해야 한다.



void block_set_xy(block_t* block, uint32_t x, uint32_t y) {
	block->x = x;
	block->y = y;

	//블럭이 바깥으로 빠져나갈경우(즉, 콘솔 좌표 120, 30을 넘어갈경우),
	//블럭이 희한하게 그려지기 때문에 이동을 제한하자.
	//블럭이 희한하게 그려지는 이유는 블럭값이 -1 이면 FFFFFF 와 같이 바뀌기 때문이다.
	if (block->x <= 0) { block->x = 0; }
	if (block->x >= MAX_BLOCK_X_POS) { block->x = MAX_BLOCK_X_POS; }
	if (block->y <= 0) { block->y = 0; }
	if (block->y >= MAX_BLOCK_Y_POS) { block->y = MAX_BLOCK_Y_POS; }

	// GPT는 역시 효율적이군
	// x 좌표를 0에서 59 사이로 제한
	//block->x = (x < 0) ? 0 : (x > 59 ? 59 : x);
	// y 좌표를 0에서 29 사이로 제한
	//block->y = (y < 0) ? 0 : (y > 29 ? 29 : y);
}

// 추가 사항: 콘솔 정보를 넘겨주지 않는 이유는? 
// 콘솔창의 사이즈가 반드시 120, 30은 아니기 때문에, 아래와 같이 콘솔 정보를 넘겨서
// 최대 최소 사이즈를 알아내는것이 더 좋기는 하지만
// void block_set_xy(console_t* console, block_t* block, uint32_t x, uint32_t y);
// block에 console인자를 넣으면
// 1. 코드만 복잡해지고
// 2. 최종 코드는 콘솔에 그릴것이 아니라 board에 그리기 때문에
// 굳이 콘솔 정보를 넣을 필요는 없다.
//void blox_set_xy(board_t* board, block_t* block, uint32_t x, uint32_t y);
