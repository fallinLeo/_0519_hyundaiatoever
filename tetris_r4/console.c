// �ܼ� �ʱ�ȭ �� ȭ�� ���� ����

#include "console.h"


// ���õ� ���� ����
char* color_strings[16] = {
    "black", // ����
    "blue", // �Ķ�
    "green", // �ʷ�
    "cyan", // û��
    "red", // ����
    "purple", // ����
    "yellow", // ���
    "white", // ���
    "gray", // ȸ��
    "light blue", // ���� �Ķ�
    "light green", // ���� ȸ��
    "light cyan", // ���� û��
    "light red", // ���� ����
    "light purple", // ���� ����
    "light yellow", // ���� ���
    "light white" // ���� ���
}; //�߰������� ���� ������ �ش� ���� 8�� ���� ������ ǥ���˴ϴ�(��: ���� �Ķ��� 9).


// ���õ� �Լ� ����
char* get_color_string(color_t color) {
    if (color >= BLACK && color <= LIGHT_WHITE) {
        return color_strings[color]; // ��ȿ�� ���� ���̸� �ش� ���ڿ� ��ȯ
    }
    else {
        return "unknown"; // ��ȿ���� ���� ���̸� �⺻�� ��ȯ
    }
}

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows) {
    console_set_size(console, cols, rows);
}

void console_init(windows_console_t* console) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    console_clear(console);

    // STD_OUTPUT_HANDLE�� ���� �ܼ� �ڵ� ��������
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // �ܼ� ȭ�� ���� ���� ��������
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // ���� �ܼ� â�� ũ�� ���� ������
        console->cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        console->rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // ���� �ܼ� â�� fore, back ���� ���� �˾ƿ���
        WORD attributes = csbi.wAttributes;
        console->fore_color = attributes & 0x0F;
        console->back_color = (attributes >> 4) & 0x0F;

        // Ŀ�� ���� �˾Ƴ���
        console->cursor_info.x = csbi.dwCursorPosition.X; // Ŀ���� X ��ǥ
        console->cursor_info.y = csbi.dwCursorPosition.Y; // Ŀ���� Y ��ǥ

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