#include "textlcd.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // LCD 초기화 및 출력
    if (!textLcdInit()) {
        fprintf(stderr, "LCD Init failed\n");
        return 1;
    }

    textLcdClear();
    textLcdWriteLine(1, argv[1]);  // 첫 줄에 인자 출력

    return 0;
}
