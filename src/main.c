#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 6

int main(int argc, char* argv[])
{
    if (gpioInitialise() < 0) {
        fprintf(stderr, "pigpio initialization failed\n");
        return 1;
    }

    gpioSetMode(PIN, PI_OUTPUT);

    float warning_threshold = 80.0f;
    float memory_usage, storage_usage;
    int running = 1;

    printf("=== Equipment Health Monitor (Project 3) ===\n");
    printf("Default Warning Threshold: %.1f%%\n", warning_threshold);

    FILE *log_file = fopen("data/status.txt", "a");

    while (running) {
        printf("\nEnter memory usage percentage: ");
        if (scanf("%f", &memory_usage) != 1) break;

        printf("Enter storage usage percentage: ");
        if (scanf("%f", &storage_usage) != 1) break;

        int is_warning = (memory_usage > warning_threshold) || (storage_usage > warning_threshold);

        if (is_warning) {
            gpioWrite(PIN, 1); // LED ON
            printf("System Status: WARNING | LED: ON\n");
        } else {
            gpioWrite(PIN, 0); // LED OFF
            printf("System Status: HEALTHY | LED: OFF\n");
        }

        if (log_file != NULL) {
            fprintf(log_file, "Memory: %.1f%%, Storage: %.1f%%, Status: %s\n",
                    memory_usage, storage_usage, is_warning ? "WARNING" : "HEALTHY");
            fflush(log_file);
        }

        printf("Run another check? (1 = Yes, 0 = Exit): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            running = 0;
        } else {
            printf("Change warning threshold? (1 = Yes, 0 = No): ");
            int update;
            scanf("%d", &update);
            if (update == 1) {
                printf("Enter new threshold: ");
                scanf("%f", &warning_threshold);
            }
        }
    }

    if (log_file != NULL) fclose(log_file);
    gpioWrite(PIN, 0);
    gpioTerminate();
    return 0;
}
