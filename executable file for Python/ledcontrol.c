#include <stdio.h>
#include <stdlib.h>
#include "led.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <led_count 0~5>\n", argv[0]);
        return 1;
    }

    int count = atoi(argv[1]);
    if (count < 0 || count > 5) {
        printf("LED count must be between 0 and 5\n");
        return 1;
    }

    if (ledLibInit() < 0) {
        perror("Failed to open LED device");
        return 1;
    }

    // 5개의 LED를 제어
    for (int i = 0; i < 5; i++) {
        if (i < count)
            ledOnOff(i, 1);  // 켜기
        else
            ledOnOff(i, 0);  // 끄기
    }

    // ledLibExit();
    return 0;
}
