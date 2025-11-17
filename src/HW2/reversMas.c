#include <stdio.h>
void reversEll(int arr[], int i, int j)
{
    int c = 0;
    j--;
    while (i < j) {
        c = arr[i];
        arr[i] = arr[j];
        arr[j] = c;
        i++;
        j--;
    }
}
void reversMas(int arr[], int m, int n)
{
    reversEll(arr, 0, m);
    reversEll(arr, m, n);
    reversEll(arr, 0, n);
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int m = 0;
    scanf("%d", &m);
    int n = sizeof(arr) / sizeof(arr[0]);
    reversMas(arr, m, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}