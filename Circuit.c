#include <stdio.h>

int main() {
    int batteryConnected = 0;
    int switchOn = 0;

    printf("\n*** Simple Electric Circuit Simulator ***\n");

    printf("Connect Battery? (1-Yes, 0-No): ");
    scanf("%d", &batteryConnected);

    if (!batteryConnected) {
        printf("Battery not connected. No current flow.\n");
        return 0;
    }

    printf("Turn Switch ON? (1-Yes, 0-No): ");
    scanf("%d", &switchOn);

    if (switchOn) {
        printf("Circuit Completed. Bulb is ON! 💡\n");
    } else {
        printf("Switch is OFF. No current flow. Bulb is OFF.\n");
    }

    return 0;
}
