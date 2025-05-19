// ��Ʈ���� ��� ���� �� �ʱ�ȭ ����

#include <string.h>

#include "blocks.h"

// ��� ��Ʈ���� ���� ����� I, J, L, O, S, T, Z 
// Total Blocks Shapes is I, J, L, O, S, T, Z

/*
1. block I
cyan �ϴû�
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Blue �Ķ���

�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Orange ������, ��Ȳ��

�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Yellow, �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Green ���
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Violet �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Red ������

�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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


// ��� �ʱ�ȭ �Լ�
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

    // �ʱ� ��ġ �� ȸ�� ����
    block->x = 0;             // �⺻ X ��ġ
    block->y = 0;             // �⺻ Y ��ġ
    block->rotation_index = 0; // �⺻ ȸ�� ���� (0)
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
	if (shape >= 0 && shape < BLOCK_MAX) { // ��ȿ�� �������� Ȯ��
		return block_string[shape];       // �ش� ��� �̸� ��ȯ
	}
	return "Unknown"; // ��ȿ���� ���� ���̸� �⺻�� ��ȯ
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
//block_rotate(&block_Z); // �Լ��� ������. �ð�������� ����? �ݽð�� ����?
void block_rotate(block_t* block) { // ȸ���� ��Ű�� �׸����� �ʴ´�.
	block->rotation_index += 1;
	block->rotation_index %= 4;
}
//ȸ���� �׸� ��� block_draw() �Լ��� ȣ���ؾ� �Ѵ�.
//block_draw(&block_Z, block_Z.x, block_Z.y);


//block_Z.x -= 1;            
//block_draw(&block_Z, block_Z.x, block_Z.y);
//block_set_pos(&block, block_Z.x - 1, block_Z.y);

// ���� x,y ��ǥ�� �̵���Ų��.
// block ������ ������� x,y�� �����ɻ����� ���� �׸����� �ʴ´�.
// ���� �׸��� �ʹٸ� block_draw() �Լ��� ȣ���ؾ� �Ѵ�.



void block_set_xy(block_t* block, uint32_t x, uint32_t y) {
	block->x = x;
	block->y = y;

	//���� �ٱ����� �����������(��, �ܼ� ��ǥ 120, 30�� �Ѿ���),
	//���� �����ϰ� �׷����� ������ �̵��� ��������.
	//���� �����ϰ� �׷����� ������ ������ -1 �̸� FFFFFF �� ���� �ٲ�� �����̴�.
	if (block->x <= 0) { block->x = 0; }
	if (block->x >= MAX_BLOCK_X_POS) { block->x = MAX_BLOCK_X_POS; }
	if (block->y <= 0) { block->y = 0; }
	if (block->y >= MAX_BLOCK_Y_POS) { block->y = MAX_BLOCK_Y_POS; }

	// GPT�� ���� ȿ�����̱�
	// x ��ǥ�� 0���� 59 ���̷� ����
	//block->x = (x < 0) ? 0 : (x > 59 ? 59 : x);
	// y ��ǥ�� 0���� 29 ���̷� ����
	//block->y = (y < 0) ? 0 : (y > 29 ? 29 : y);
}

void block_draw(block_t* block) {
	//blk->x = x;
	//blk->y = y;

	// �ʱ� ��ǥ ����
	uint32_t initial_x = block->x * 2; // X ��ǥ�� �� ��� Ȯ��
	uint32_t initial_y = block->y;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			// ��� �����Ͱ� �ִ� ��츸 ���
			if (block->att[block->rotation_index][i][j] == 1) {
				setcolor(block->color, BLACK); // ��� ���� ����
				SetCurrentCursorPos(initial_x + j * 2, initial_y + i); // Ŀ�� ��ġ ����
				printf("��");
				setcolor(WHITE, BLACK);
			}
			else {
				SetCurrentCursorPos(initial_x + j * 2, initial_y + i); // �� �� ��ġ ����
				printf("��");
				//printf("  ");
			}
		}
	}

	// �⺻ �������� ����
	setcolor(WHITE, BLACK);
}

// �߰� ����: �ܼ� ������ �Ѱ����� �ʴ� ������? 
// �ܼ�â�� ����� �ݵ�� 120, 30�� �ƴϱ� ������, �Ʒ��� ���� �ܼ� ������ �Ѱܼ�
// �ִ� �ּ� ����� �˾Ƴ��°��� �� ����� ������
// void block_set_xy(console_t* console, block_t* block, uint32_t x, uint32_t y);
// block�� console���ڸ� ������
// 1. �ڵ常 ����������
// 2. ���� �ڵ�� �ֿܼ� �׸����� �ƴ϶� board�� �׸��� ������
// ���� �ܼ� ������ ���� �ʿ�� ����.
//void blox_set_xy(board_t* board, block_t* block, uint32_t x, uint32_t y);
