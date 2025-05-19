// 콘솔 초기화 및 화면 제어 관련

#include "console.h"


// 관련된 변수 선언
char* color_strings[16] = {
    "black", // 검정
    "blue", // 파랑
    "green", // 초록
    "cyan", // 청록
    "red", // 빨강
    "purple", // 자주
    "yellow", // 노랑
    "white", // 흰색
    "gray", // 회색
    "light blue", // 밝은 파랑
    "light green", // 밝은 회색
    "light cyan", // 밝은 청록
    "light red", // 밝은 빨강
    "light purple", // 밝은 자주
    "light yellow", // 밝은 노랑
    "light white" // 밝은 흰색
}; //추가적으로 밝은 색상은 해당 값에 8을 더한 값으로 표현됩니다(예: 밝은 파랑은 9).


// 관련된 함수 내용
char* get_color_string(color_t color) {
    if (color >= BLACK && color <= LIGHT_WHITE) {
        return color_strings[color]; // 유효한 색상 값이면 해당 문자열 반환
    }
    else {
        return "unknown"; // 유효하지 않은 값이면 기본값 반환
    }
}

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows) {
    console_set_size(console, cols, rows);
}

void console_init(windows_console_t* console) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    console_clear(console);

    // STD_OUTPUT_HANDLE을 통해 콘솔 핸들 가져오기
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 콘솔 화면 버퍼 정보 가져오기
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // 현재 콘솔 창의 크기 정보 얻어오기
        console->cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        console->rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // 현재 콘솔 창의 fore, back 색상 정보 알아오기
        WORD attributes = csbi.wAttributes;
        console->fore_color = attributes & 0x0F;
        console->back_color = (attributes >> 4) & 0x0F;

        // 커서 정보 알아내기
        console->cursor_info.x = csbi.dwCursorPosition.X; // 커서의 X 좌표
        console->cursor_info.y = csbi.dwCursorPosition.Y; // 커서의 Y 좌표

        console->cursor_info.is_hide = get_cursor_visibility();
        //set_cursor_visibility(console->cursor_info.is_hide);

        //console_resize(const windows_console_t * console, uint32_t cols, uint32_t rows) {
        console_resize(&console, RESIZE_COLS, RESIZE_ROWS);
    }
    else {
        printf("Unable to get console window information.\n");

        printf("Error: Unable to get console cursor position.\n");
        console->cursor_info.x = -1;
        console->cursor_info.y = -1;
    }
    //printf("cosole (cols,rows)= %d,%d", console->cols, console->rows);
}