#include "bubbleSort.h"
#include <stdbool.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int matching(int* arr1, int* arr2, int lenArr)
{
    int k = 0;
    for (int i = 0; i < lenArr; i++) {
        if (arr1[i] == arr2[i]) {
            k++;
        }
    }
    return lenArr - k;
}