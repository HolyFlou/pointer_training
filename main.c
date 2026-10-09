#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int size = 5;

    int static_arr[] = {10, 20, 30, 40, 50};

    printf("Статичний масив\n");
    printf("Індекс\tЗа індексом\tЗа розіменуванням\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\n", i, static_arr[i], *(static_arr + i));
    }


    int *dyn_arr = (int *)malloc(size * sizeof(int));
    if (dyn_arr == NULL) {
        printf("\nПомилка виділення пам'яті\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        dyn_arr[i] = (i + 1) * 100;
    }

    printf("\nДинамічний масив\n");
    printf("Індекс\tЗа індексом\tЗа розіменуванням\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\n", i, dyn_arr[i], *(dyn_arr + i));
    }

    free(dyn_arr);

    return 0;
}