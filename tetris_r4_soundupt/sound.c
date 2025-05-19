#include "sound.h"
#include "console.h"


void sound_init(const char file_name) {

}

void sound_play(const char* file_path) {
    //const char* filename = "sample2.wav";
    if (PlaySoundA(file_path, NULL, SND_ASYNC | SND_LOOP | SND_FILENAME)) {
        printf("Playing sound: %s\n", file_path);
    }
    else {
        printf("Error: Unable to play sound. Make sure the file exists and is a valid .wav file.\n");
    }
}
void sound_stop(void) {
    PlaySoundA(NULL, NULL, 0);
}