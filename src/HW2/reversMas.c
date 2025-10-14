#include <stdio.h>
void reversMas(int mas[], int i, int j)
{
    int c;
    j--;
    for (i, j; i < j; i++, j--){
        c = mas[i];
        mas[i] = mas[j];
        mas[j] = c;
    }
}
int main()
{
    int mas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m;
    scanf("%d", &m);
    int n = sizeof(mas) / sizeof(mas[0]);
    reversMas(mas, 0, m);
    reversMas(mas, m, n);
    reversMas(mas, 0, n);
    for (int i = 0; i < n; i++){
        printf("%d ", mas[i]);
    }
    printf("\n");
}