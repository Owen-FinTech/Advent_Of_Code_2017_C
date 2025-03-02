#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 16   // Maximum lines
#define MAX_INTS  16    // Maximum integers per line

int main() {
    FILE *file;
    int array[MAX_LINES][MAX_INTS] = {0};
    char line[1024];
    int lineCount = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, sizeof(line), file) && lineCount < MAX_LINES) {
        int colCount = 0;
        char *token = strtok(line, "\t\n");
        while (token != NULL && colCount < MAX_INTS) {
            array[lineCount][colCount] = atoi(token);
            colCount++;
            token = strtok(NULL, "\t\n");
        }
        lineCount++;
    }

    fclose(file);

    int sum = 0;
    for (int i = 0; i < lineCount; ++i) {
        int min = array[i][0];
        int max = array[i][0];
        for (int j = 0; j < MAX_INTS; ++j) {
            if (array[i][j] < min) {
                min = array[i][j];
            }

            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
        sum += max - min;
    }

    printf("%d\n", sum);

    return 0;
}
