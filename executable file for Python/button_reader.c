#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main() {
    const char *device = "/dev/input/event4";  // 필요 시 자동 탐색으로 변경 가능
    int fd = open(device, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct input_event ev;
    while (read(fd, &ev, sizeof(ev)) > 0) {
        if (ev.type == EV_KEY) {
            printf("%d %d\n", ev.code, ev.value);  // stdout으로 전송
            fflush(stdout);
        }
    }

    close(fd);
    return 0;
}
