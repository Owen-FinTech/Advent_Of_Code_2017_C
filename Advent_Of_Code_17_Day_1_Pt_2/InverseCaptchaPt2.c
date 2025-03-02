#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int arr[5000];
    int arrSize = 0;
    int ch;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch >= '0' && ch <= '9') { 
            arr[arrSize] = ch - '0';  
            arrSize++;
        }
        
        if (arrSize >= 5000) {
            break;
        }
    }

    fclose(file);
    int sum = 0;

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] == arr[(i + (arrSize / 2)) % arrSize]) {
            sum += arr[i];
        }
    }

    printf("Sum: %d\n", sum);

    return 0;
}