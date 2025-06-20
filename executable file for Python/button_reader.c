#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>
#include "button.h"

int main(void)
{
    BUTTON_MSG_T msg;

    if (!buttonInit()) {
        fprintf(stderr, "button init failed\n");
        return 1;
    }

    int msgID = msgget(MESSAGE_ID, IPC_CREAT | 0666);
    if (msgID == -1) {
        perror("msgget failed");
        return 1;
    }

    while (1)
    {
        if (msgrcv(msgID, &msg, sizeof(msg) - sizeof(long), 0, 0) > 0)
        {
            // 버튼 입력 감지 출력
            printf("%d %d\n", msg.keyInput, msg.pressed);
            fflush(stdout);  // Python subprocess에서 출력 읽게 함
        }
    }

    buttonExit();
    return 0;
}
