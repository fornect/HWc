#include <stdio.h>

int countZero(int n, int* arr)
{
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            k++;
        }
    }
    return k;
}

int main()
{
    int n = 0;
    printf("введите количество элементов массива:");
    scanf("%d", &n);
    int arr[n] = {};
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("%d\n", countZero(n, arr));
    return 0;
}