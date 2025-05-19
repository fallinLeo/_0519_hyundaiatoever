#include "key_driver.h"

// _kbhit()= 어떤 버튼이라도 눌려졌나요? Were any buttons pressed?
bool any_key_pressed() {
    bool result = false;
#ifdef __MSC__
    result = _kbhit();
#endif

#ifdef __ESP32__
    result = true;
#endif
    return result;
}

uint8_t get_key() {
    uint8_t result = 0;
#ifdef __MSC__
    result = _getch();
#endif
#ifdef __ESP32__
    result = digitalRead(); // parameter를 뭘로 주나? 자꾸 일이 커지는데? ^^
#endif
    return result;
}


void key_init() {
    // MSC에서는 딱히 초기화 할것이 없다.
}

uint16_t key_get_code() {
    key_t key = { .all = 0 };

    if (any_key_pressed()) {
        key.bound.lower = get_key();
        if ((key.bound.lower == EXT_CODE_1) || (key.bound.lower == EXT_CODE_2)) {
            key.bound.upper = get_key();
        }
        else {            
            key.bound.upper = key.bound.lower;
            key.bound.lower = 0; // 이렇게 해도 되고
            //key.all >>= 8; // 이렇게 해도 된다.
            //key.bound.upper >> 8;
        }
    }
    //return key.all; // 이렇게 하게 되면 return type을 key_t로 해야 하는데 
    // 받는 함수에서 영 불편하다.
    return key.all; // 그냥 uint16_t를 돌려주는게 받는 쪽에서 편하다.
}

void key_print(uint16_t key_val) {
    static int key_cnt = 0;
    printf("[%d] 0x%04X\n", ++key_cnt, key_val);
}

uint16_t key_read() {
    uint16_t key_code = 0;

    key_code = key_get_code();

    switch (key_code) {
        // 0,1,2,3,... 
        case KEY_1: key_print(key_code); break;
        case KEY_2: key_print(key_code); break;
        case KEY_3: key_print(key_code); break;
        case KEY_4: key_print(key_code); break;
        case KEY_5: key_print(key_code); break;
        case KEY_6: key_print(key_code); break;
        case KEY_7: key_print(key_code); break;
        case KEY_8: key_print(key_code); break;
        case KEY_9: key_print(key_code); break;

        // a,b,c,d,...
        case KEY_a: case KEY_A: key_print(key_code); break;
        case KEY_b: case KEY_B: key_print(key_code); break;
        case KEY_c:	case KEY_C: key_print(key_code); break;
        case KEY_d:	case KEY_D: key_print(key_code); break;
        case KEY_e:	case KEY_E: key_print(key_code); break;
        case KEY_f:	case KEY_F: key_print(key_code); break;
        case KEY_g:	case KEY_G: key_print(key_code); break;
        case KEY_h:	case KEY_H: key_print(key_code); break;
        case KEY_i:	case KEY_I: key_print(key_code); break;
        case KEY_j:	case KEY_J: key_print(key_code); break;
        case KEY_k:	case KEY_K: key_print(key_code); break;
        case KEY_l:	case KEY_L: key_print(key_code); break;
        case KEY_m:	case KEY_M: key_print(key_code); break;
        case KEY_n:	case KEY_N: key_print(key_code); break;
        case KEY_o:	case KEY_O: key_print(key_code); break;
        case KEY_p:	case KEY_P: key_print(key_code); break;
        case KEY_q:	case KEY_Q: key_print(key_code); break;
        case KEY_r:	case KEY_R: key_print(key_code); break;
        case KEY_s:	case KEY_S: key_print(key_code); break;
        case KEY_t:	case KEY_T: key_print(key_code); break;
        case KEY_u:	case KEY_U: key_print(key_code); break;
        case KEY_v:	case KEY_V: key_print(key_code); break;
        case KEY_w:	case KEY_W: key_print(key_code); break;
        case KEY_x:	case KEY_X: key_print(key_code); break;
        case KEY_y:	case KEY_Y: key_print(key_code); break;
        case KEY_z:	case KEY_Z: key_print(key_code); break;

        // ESC, ENTER, SAPCE, ...
        case KEY_ESC: key_print(key_code);  break;
        case KEY_ENTER: key_print(key_code); break;
        case KEY_SPACE: key_print(key_code); break;

        // F1, F2, F3, ...
        case KEY_F1: key_print(key_code); break;
        case KEY_F2: key_print(key_code); break;
        case KEY_F3: key_print(key_code); break;
        case KEY_F4: key_print(key_code); break;
        case KEY_F5: key_print(key_code); break;
        case KEY_F6: key_print(key_code); break;

        //case KEY_F7: key_print(key_val); break;
        //case KEY_F8: key_print(key_val); break;
        //case KEY_F9: key_print(key_val); break;
        //case KEY_F10: key_print(key_val); break;
        case KEY_F11: key_print(key_code); break;
        case KEY_F12: key_print(key_code); break;

        // Up, Down, Left, Right...
        case KEY_UP: key_print(key_code); break;
        case KEY_DOWN: key_print(key_code); break;
        case KEY_LEFT: key_print(key_code); break;
        case KEY_RIGHT: key_print(key_code); break;
        case KEY_INS: key_print(key_code); break;
        case KEY_DEL: key_print(key_code); break;
        case KEY_HOME: key_print(key_code); break;
        case KEY_END: key_print(key_code); break;
        case KEY_PAGE_UP: key_print(key_code); break;
        case KEY_PAGE_DOWN: key_print(key_code); break;
    }
}
