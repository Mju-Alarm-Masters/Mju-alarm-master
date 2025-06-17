#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>   
#include "colorled.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <red|green>\n", argv[0]);
        return 1;
    }

    ColorLEDInit();

    if (strcmp(argv[1], "red") == 0) {
        ColorLEDSetColor(100, 0, 0);     // 빨강
    } else if (strcmp(argv[1], "green") == 0) {
        ColorLEDSetColor(0, 100, 0);     // 초록
    } else {
        printf("Invalid color: %s\n", argv[1]);
        return 1;
    }

    sleep(3);  

    ColorLEDClose();  // PWM disable 및 unexport (LED 꺼짐)

    return 0;
}
