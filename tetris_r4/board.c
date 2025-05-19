// 게임 보드 전체 상태 및 블록 위치 삽입/이동 관련

#include <stdio.h>

#include "board.h"



// ----------------------------------
// 테트리스의 표준적인 게임 필드 크기는 가로 10블록, 세로 20블록입니다.
#define BOARD_WIDTH 10 + 2 // 2가 늘어난것은 왼쪽 오른쪽 Wall Cell이다.
#define BOARD_HEIGHT 20 + 1 // 1이 늘어난것은 위와 마찬가지로 Bottom Cell

// 전체 보드 전역 변수
cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0, };

// 블럭의 초기 정보를 갖고 있는 데이터
cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH] = {
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (0,0),(0,1),(0,2),(0,3),(0,4),(0,5),(0,6),(0,7),(0,8),(0,9),(0,10),(0,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (1,0),(1,1),(1,2),(1,3),(1,4),(1,5),(1,6),(1,7),(1,8),(1,9),(1,10),(1,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (2,0),(2,1),(2,2),(2,3),(2,4),(2,5),(2,6),(2,7),(2,8),(2,9),(2,10),(2,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (3,0),(3,1),(3,2),(3,3),(3,4),(3,5),(3,6),(3,7),(3,8),(3,9),(3,10),(3,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (4,0),(4,1),(4,2),(4,3),(4,4),(4,5),(4,6),(4,7),(4,8),(4,9),(4,10),(4,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (5,0),(5,1),(5,2),(5,3),(5,4),(5,5),(5,6),(5,7),(5,8),(5,9),(5,10),(5,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(6,6),(6,7),(6,8),(6,9),(6,10),(6,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (7,0),(7,1),(7,2),(7,3),(7,4),(7,5),(7,6),(7,7),(7,8),(7,9),(7,10),(7,11)
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (18,0),(18,1),(18,2),(18,3),(18,4),(18,5),(18,6),(18,7),(18,8),(18,9),(18,10),(18,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (19,0),(19,1),(19,2),(19,3),(19,4),(19,5),(19,6),(19,7),(19,8),(19,9),(19,10),(19,11)
    { W, W, W, W, W, W, W, W, W, W, W, W }, // (20,0),(20,1),(20,2),(20,3),(20,4),(20,5),(20,6),(20,7),(20,8),(20,9),(20,10),(20,11)
};

#define BOARD_START_X (4)
#define BOARD_START_Y (4)
// ■          ■ // (0,0),(1,0),(2,0),(n,0), ...
// ■          ■ // (0,1),
// ■          ■ // (0,2),
// .............. 
// ■■■■■■■ // (0,n),

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            //cell_init(&gboard[i][j], 0, 0, YELLOW);

            // old 이렇게 하면 좋지 않다는 예를 보여주기 위한 나쁜 코드
            //board[i][j].point.x = j;
            //board[i][j].point.y = i;
            //board[i][j].att = E; // 모두 E로 만들면 벽을 그릴때 작성해야 할 코드가 늘어난다.
            gboard[i][j].point.x = BOARD_START_X + j;
            gboard[i][j].point.y = BOARD_START_Y + i;
            gboard[i][j].att = data[i][j]; // 별도의 보드 데이터를 만든후 삽입하는게 훨씬
            // 코딩이 간편
            // 보기도 깔끔, 가독성 우수
            // 보드를 수정 하기도 매우 쉽다.
            gboard[i][j].color = YELLOW;
        }
    }
};

// 보드 정보를 출력한다.
// 그런데 그리 유용하지 않은데
// 텍스트로 나와서 보기 불편하고, (10,10,N)
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("(%d,%d)", board[i][j].point.x, board[i][j].point.y);
            //printf("%d ", board[i][j].att);
        }
        printf("\r\n");
    }
}

#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

// 블럭을 움직이는 아주 기본적인 함수
// 충돌 체크를 하지 않는다. 충돌체크를 해보자.
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


// 현재 상태의 보드를 그린다.
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

// 보드 내의 벽을 제외한 모든 속성 데이터들을 지운다.
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

// block 배열을 현재 위치(block_x, block_y)를 기준으로 board에 복사합니다.
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