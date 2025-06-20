#include <stdio.h>      // printf
#include <string.h>     // strcmp
#include <signal.h>     // signal, SIGINT, SIGTERM
#include <unistd.h>     // usleep
#include "buzzer.h"     // buzzerInit, buzzerPlaySong, buzzerStopSong

volatile sig_atomic_t keepRunning = 1;

void intHandler(int sig) {
    keepRunning = 0;
}

int main(int argc, char *argv[]) {
    buzzerInit();

    if (argc > 1 && strcmp(argv[1], "off") == 0) {
        buzzerStopSong();
        return 0;
    }

    signal(SIGINT, intHandler);
    signal(SIGTERM, intHandler);

    while (keepRunning) {
        buzzerPlaySong(1);
        usleep(300000);  // 0.3초 울림
        buzzerStopSong();
        usleep(50000);   // 0.05초 대기
    }

    buzzerStopSong();
    return 0;
}
