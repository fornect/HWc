#include "bubbleSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// чтобы скомпилировать используйте gcc bubbleSort.c 1.c и поставте все необходимые флаги
int main()
{
    int lenArr = 2;
    int* notSortArr = (int*)malloc(lenArr * sizeof(int));
    printf("Введите нажимая после каждого ENTER, чтобы законьчить ввод введите 0:\n");
    int i = 1;
    scanf("%d", &notSortArr[0]);
    while (notSortArr[i - 1] != 0) {
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

    int elemValue = 0;
    int elemCount = 0;
    for (int l = 0; l <= i; l++) {

        if (elemValue == sortArr[l]) {
            elemCount++;
        } else {
            if (sortArr[l - 1] != 0 && elemCount != 0) {
                printf("%d %s %d %s\n", elemValue, "встречаеться в наборе", elemCount, "раз");
            }
            elemValue = sortArr[l];
            elemCount = 1;
        }
    }
}