// 콘솔 초기화 및 화면 제어 관련

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

#define DEFAULT_COLS 120
#define DEFAULT_ROWS 30

#define RESIZE_COLS (DEFAULT_COLS-30) //=90
#define RESIZE_ROWS 30


// 관련된 변수형(구조체) 선언
typedef enum _color_t {
    BLACK, //0
    BLUE, // 1
    GREEN,
    CYAN,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_PURBPLE,
    LIGHT_YELLOW,
    LIGHT_WHITE,
} color_t; //추가적으로 밝은 색상은 해당 값에 8을 더한 값으로 표현됩니다(예: 밝은 파랑은 9).

typedef struct _cursor_info_t {
    uint32_t x;
    uint32_t y;
    bool is_hide;
} cursor_info_t;

typedef struct _windows_console_t {
    uint32_t cols;
    uint32_t rows;

    color_t fore_color;
    color_t back_color;

    cursor_info_t cursor_info;
} windows_console_t;


// 관련된 함수 프로토타입 선언
char* get_color_string(color_t color);
void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);
void console_init(windows_console_t* console);