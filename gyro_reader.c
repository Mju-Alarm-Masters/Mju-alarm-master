#include <stdio.h>
#include "accelMagGyro.h"

int main() {
    SensorData gyro;
    if (readGyroscope(&gyro) == 0) {
        printf("%d %d\n", gyro.x, gyro.y);  
        return 0;
    } else {
        fprintf(stderr, "Failed to read gyroscope data\n");
        return 1;
    }
}
