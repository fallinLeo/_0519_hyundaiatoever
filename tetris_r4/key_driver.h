// 키보드 입력을 처리하는 인터페이스 제공

#ifndef __KEY_DRIVER_H__
#define __KEY_DRIVER_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "key_config.h"
#include "key_code.h"

typedef union _key_t {
    uint16_t all;
    struct {
        uint8_t upper;
        uint8_t lower;
    } bound;
} key_t;

// qqq(1)
// 함수 이름을 read_key > key_read로 바꿈
void key_init();
//uint16_t read_key();
uint16_t key_get_code();
//void print_key(uint16_t key_val);
void key_print(uint16_t key_val);
//void key_write(); // 입력장치이기 때문에 write는 필요없다.

uint16_t key_read();

#endif
