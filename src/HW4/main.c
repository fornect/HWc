#include "bubbleSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int lenArr = 2;

    int* notSortArr = (int*)malloc(lenArr * sizeof(int));
    printf("Введите числа через пробел, нажмите ENTER чтобы прекратить ввод:");
    int i = 1;
    scanf("%d", &notSortArr[0]);
    while (getchar() != '\n') {
        if (i == lenArr - 1) {
            int* notSortArrNew = (int*)malloc(2 * lenArr * sizeof(int));
            memcpy(notSortArrNew, notSortArr, lenArr * sizeof(int));
            lenArr = lenArr * 2;
            free(notSortArr);
            notSortArr = notSortArrNew;
        }
        scanf("%d", &notSortArr[i]);
        i++;
    }
    int* sortArr = (int*)malloc(i * sizeof(int));
    memcpy(sortArr, notSortArr, i * sizeof(int));
    bubbleSort(sortArr, i);
    return matching(notSortArr, sortArr, i);
}