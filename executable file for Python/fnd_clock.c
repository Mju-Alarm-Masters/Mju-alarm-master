#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "fnd.h"

volatile sig_atomic_t keepRunning = 1;

void intHandler(int dummy) {
    keepRunning = 0;
}

int main() {
    signal(SIGINT, intHandler);  // Ctrl+C 등 종료 대응
    signal(SIGTERM, intHandler); // subprocess에서 kill 시 종료

    while (keepRunning) {
        fndDispTime();        // 현재 시각 hhmmss 표시
        sleep(1);
    }

    // FND 지우고 종료
    fndDisp(0, 0);
    return 0;
}
