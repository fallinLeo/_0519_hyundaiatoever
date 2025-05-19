#ifndef SOUND_H
#define SOUND_H

#include "console.h"
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib") // winmm 라이브러리 링크

void sound_init(const char file_name);
void sound_play(const char* file_path);
void sound_stop(void);

#endif
