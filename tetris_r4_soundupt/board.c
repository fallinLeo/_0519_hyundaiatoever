// ���� ���� ��ü ���� �� ��� ��ġ ����/�̵� ����

#include <stdio.h>

#include "board.h"
//cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0, };

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            //cell_init(&gboard[i][j], 0, 0, YELLOW);

            // old �̷��� �ϸ� ���� �ʴٴ� ���� �����ֱ� ���� ���� �ڵ�
            //board[i][j].point.x = j;
            //board[i][j].point.y = i;
            //board[i][j].att = E; // ��� E�� ����� ���� �׸��� �ۼ��ؾ� �� �ڵ尡 �þ��.
            gboard[i][j].point.x = BOARD_START_X + j;
            gboard[i][j].point.y = BOARD_START_Y + i;
            gboard[i][j].att = data[i][j]; // ������ ���� �����͸� ������ �����ϴ°� �ξ�
            // �ڵ��� ����
            // ���⵵ ���, ������ ���
            // ���带 ���� �ϱ⵵ �ſ� ����.
            gboard[i][j].color = YELLOW;
        }
    }
};

// ���� ������ ����Ѵ�.
// �׷��� �׸� �������� ������
// �ؽ�Ʈ�� ���ͼ� ���� �����ϰ�, (10,10,N)
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("(%d,%d)", board[i][j].point.x, board[i][j].point.y);
            //printf("%d ", board[i][j].att);
        }
        printf("\r\n");
    }
}
// ���� �����̴� ���� �⺻���� �Լ�
// �浹 üũ�� ���� �ʴ´�. �浹üũ�� �غ���.
// moveBlockOnBaord, move_block_on_board
//board_move_block(&console, gboard, &my_block, DIR_UP);
void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir) {
    board_clear_data(board);

    switch (dir) {
    case DIR_UP:
        block->y -= 1;
        break;

    case DIR_DOWN:
        block->y += 1;
        break;

    case DIR_LEFT:
        block->x -= 1;
        break;

    case DIR_RIGHT:
        block->x += 1;
        break;

    }
    board_insert_block(board, block, block->x, block->y);
    board_draw(console, gboard);
}

//void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir) {
//
//}

// rotateBlockOnBoard, roate_block_on_board
void board_roate_block(block_t* block) {

}


// ���� ������ ���带 �׸���.
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            switch (board[i][j].att) {
            case W:
                console_set_fore_color(console, GREEN);
                cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case N:
                //console_set_fore_color(console, board[i][j].color);
                console_set_fore_color(console, RED);
                cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case E:
                //console_set_fore_color(console, board[i][j].color);
                console_set_fore_color(console, WHITE);
                cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;
            }
        }
    }
}

void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y) {
    cell->point.x = cell_x;
    cell->point.y = cell_y;
    //printf("cell pos(x,y)=(%d,%d)\r\n", cell->point.x, cell->point.y);
    board[cell->point.y][cell->point.x].att = cell->att;
}

// ���� ���� ���� ������ ��� �Ӽ� �����͵��� �����.
// clear_board_data(board);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j].att == N) {
                board[i][j].att = E;
            }
        }
    }
}

// block �迭�� ���� ��ġ(block_x, block_y)�� �������� board�� �����մϴ�.
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y) {
    block->x = block_x;
    block->y = block_y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            board[block->y + i][block->x + j].att = block->att[block->rotation_index][i][j];
            //printf("block pos(x,y)=(%02d,%02d)\r\n", block->x, block -> y);
            //printf("(%d,%d)=%d,", i, j, block->att[block->rotation_index][i][j]);
        }
        printf("\r\n");
    }
}