#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char input[10]; // Buffer slightly larger to safely catch over-length inputs

    while (1) {
        printf("Enter 24-hour clock time: ");
        scanf("%s", input);

        if (strcmp(input, "9990") == 0) {
            printf("End of the program\n");
            break; // Exits the while loop properly
        }

        int legal = 1;
        if (strlen(input) != 4) {
            legal = 0;
        } else {
            for (int i = 0; i < 4; i++) {
                if (!isdigit(input[i])) {
                    legal = 0;
                    break;
                }
            }
        }

        if (!legal) {
            printf("Error\nillegal time\n");
            continue;
        }

        int time = atoi(input);
        int hour = time / 100;
        int minute = time % 100;

        // Validating the parsed 24-hour time
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
            printf("Error\nillegal time\n");
            continue;
        }

        printf("The digits you need to connect are:\n");

        // Iterate across the four columns (1000, 100, 10, 1) using a for-loop
        for (int h = 1000; h >= 1; h /= 10) {
            // Formula to extract digit per lab spec
            int digit = (time % (10 * h)) / h;

            // Calculate segment offset (increases by 10 from right to left)
            int offset = 0;
            if (h == 1000) offset = 30;
            else if (h == 100) offset = 20;
            else if (h == 10) offset = 10;
            else if (h == 1) offset = 0;

            // Output base segments + offset, or ignore if not 1, 2, or 3
            if (digit == 1) {
                printf("Digit 1 needs %d %d\n", 2 + offset, 5 + offset);
            } else if (digit == 2) {
                printf("Digit 2 needs %d %d %d %d %d\n", 1 + offset, 2 + offset, 3 + offset, 6 + offset, 7 + offset);
            } else if (digit == 3) {
                printf("Digit 3 needs %d %d %d %d %d\n", 1 + offset, 2 + offset, 3 + offset, 5 + offset, 6 + offset);
            } else {
                printf("Digit %d ignored\n", digit);
            }
        }
    }

    return 0; // Return is safely outside the while loop now
}
