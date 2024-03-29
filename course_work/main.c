#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    srand(time(NULL));  // Инициализация генератора случайных чисел

    printf("Сгенерированный массив: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;  // Генерация случайного числа от 0 до 9
    }

    //Выделяем память для отсортированных массивов
    int* shellarr = (int*)malloc(n * sizeof(int));
    if (shellarr == NULL) {
        printf("Ошибка выделения памяти.\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        shellarr[i] = arr[i];
    }

    int* mergearr = (int*)malloc(n * sizeof(int));
    if (mergearr == NULL) {
        printf("Ошибка выделения памяти.\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        mergearr[i] = arr[i];
    }

    clock_t start, end;
    double cpu_time_used;

    // Сортировка Shell
    start = clock();
    shellSort(shellarr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Shell sort завершена за %.5f секунд.\n", cpu_time_used);

    // Сортировка слиянием
    start = clock();
    mergeSort(mergearr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort завершена за %.5f секунд.\n", cpu_time_used);

    // Вывод массивов (если выбрано пользователем)
    int choice;
    printf("Хотите вывести отсортированные массивы? (1 - Да, 0 - Нет): ");
    scanf("%d", &choice);

    if (choice) {
        printf("Исходный массив: ");
        printArray(arr, n);

        printf("Shell sort: ");
        printArray(shellarr, n);

        printf("Merge sort: ");
        printArray(mergearr, n);
    }

    free(arr);
    free(shellarr);

    return 0;
}