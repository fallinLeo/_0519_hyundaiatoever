// 키보드 키 코드 매핑 정의

#define _CRT_SECURE_NO_WARNINGS // VS 경고 때문에 적어놓은것임

#ifndef __KEY_CODE_H__
#define __KEY_CODE_H__

#include <stdio.h>
#include <stdint.h>

#ifdef __MSC__
#include <conio.h>  // _getch(), _Kbhit qqq 이식성을 위해 제거하자
#endif

#define EXT_CODE_1		(0x00) // 확장키가 00인 키값이 있고.. F1, F2, F3
#define EXT_CODE_2		(0xE0) // 확장키가 E0인 키값이 있다.. Up, Down, Left, Right..

// 0,1,2,...9
#define KEY_0			(0x30) // Decimal 48  // 키패드의 0과 이 qwer위에 있는 0과는 키값이 다르다.
#define KEY_1			(KEY_0+1) // 49
#define KEY_2			(KEY_0+2) // 50
#define KEY_3			(KEY_0+3) // 51
#define KEY_4			(KEY_0+4) // 52
#define KEY_5			(KEY_0+5)
#define KEY_6			(KEY_0+6)
#define KEY_7			(KEY_0+7)
#define KEY_8			(KEY_0+8)
#define KEY_9			(KEY_0+9) 

// a,b,c,d... z
#define KEY_a           (0x61)
#define KEY_b           (KEY_a+1)
#define KEY_c           (KEY_a+2) // KEY_a+1, KEY_a+2, KEY_a+3, 와 같이 나간다.
#define KEY_d           (KEY_a+3)
#define KEY_e           (KEY_a+4)
#define KEY_f           (KEY_a+5)
#define KEY_g           (KEY_a+6)
#define KEY_h           (KEY_a+7)
#define KEY_i           (KEY_a+8)
#define KEY_j           (KEY_a+9)
#define KEY_k           (KEY_a+10)
#define KEY_l           (KEY_a+11)
#define KEY_m           (KEY_a+12)
#define KEY_n           (KEY_a+13)
#define KEY_o           (KEY_a+14)
#define KEY_p           (KEY_a+15)
#define KEY_q           (KEY_a+16)
#define KEY_r           (KEY_a+17)
#define KEY_s           (KEY_a+18)
#define KEY_t           (KEY_a+19)
#define KEY_u           (KEY_a+20)
#define KEY_v           (KEY_a+21)
#define KEY_w           (KEY_a+22)
#define KEY_x           (KEY_a+23)
#define KEY_y           (KEY_a+24)
#define KEY_z           (KEY_a+25)

// A,B,C,D,...Z
#define KEY_A           (KEY_a-0x20)
#define KEY_B           (KEY_b-0x20)
#define KEY_C           (KEY_c-0x20) // KEY_a-0x20, KEY_b-0x20, KEY_c-0x20,.. 과 같이 나간다.
#define KEY_D           (KEY_d-0x20)
#define KEY_E           (KEY_e-0x20)
#define KEY_F           (KEY_f-0x20)
#define KEY_G           (KEY_g-0x20)
#define KEY_H           (KEY_h-0x20)
#define KEY_I           (KEY_i-0x20)
#define KEY_J           (KEY_j-0x20)
#define KEY_K           (KEY_k-0x20)
#define KEY_L           (KEY_l-0x20)
#define KEY_M           (KEY_m-0x20)
#define KEY_N           (KEY_n-0x20)
#define KEY_O           (KEY_o-0x20)
#define KEY_P           (KEY_p-0x20)
#define KEY_Q           (KEY_q-0x20)
#define KEY_R           (KEY_r-0x20)
#define KEY_S           (KEY_s-0x20)
#define KEY_T           (KEY_t-0x20)
#define KEY_U           (KEY_u-0x20)
#define KEY_V           (KEY_v-0x20)
#define KEY_W           (KEY_w-0x20)
#define KEY_X           (KEY_x-0x20)
#define KEY_Y           (KEY_y-0x20)
#define KEY_Z           (KEY_z-0x20)

// F1,F2,F3...F12
#define	KEY_F1			(0x3B | (EXT_CODE_1 << 8)) // 003B
#define KEY_F2			(0x3C | (EXT_CODE_1 << 8)) // 003C
#define KEY_F3			(0x3D | (EXT_CODE_1 << 8)) // 003D
#define KEY_F4			(0x3E | (EXT_CODE_1 << 8)) // 003E
#define KEY_F5			(0x3F | (EXT_CODE_1 << 8))
#define KEY_F6			(0x40 | (EXT_CODE_1 << 8))
#define KEY_F7			(0x41 | (EXT_CODE_1 << 8)) // 0x41과 값이 겹친다?
#define KEY_F8			(0x42 | (EXT_CODE_1 << 8))
#define KEY_F9			(0x43 | (EXT_CODE_1 << 8))
#define KEY_F10			(0x44 | (EXT_CODE_1 << 8))
#define KEY_F11			(0x85 | (EXT_CODE_2 << 8)) // 45가 아니다! 85? 57? 대체 모야? E085
#define KEY_F12			(0x86 | (EXT_CODE_2 << 8))


// INS,DEL,HOME...
#define KEY_INS         (0x52 | (EXT_CODE_2 << 8)) 
#define KEY_DEL         (0x53 | (EXT_CODE_2 << 8))
#define KEY_HOME        (0x47 | (EXT_CODE_2 << 8))
#define KEY_END         (0x4F | (EXT_CODE_2 << 8))
#define KEY_PAGE_UP     (0x49 | (EXT_CODE_2 << 8))
#define KEY_PAGE_DOWN   (0x51 | (EXT_CODE_2 << 8))

//Up, Down, Left, Right
#define KEY_UP          (0x48 | (EXT_CODE_2 << 8))
#define KEY_DOWN        (0x50 | (EXT_CODE_2 << 8))
#define KEY_LEFT        (0x4B | (EXT_CODE_2 << 8))
#define KEY_RIGHT       (0x4D | (EXT_CODE_2 << 8))

// ESC, ENTER, SAPCE
#define KEY_ESC         (0x1B) // ESC가 특수키가 아니었어?
#define KEY_ENTER       (0x0D)
#define KEY_SPACE       (0x20)

#endif
