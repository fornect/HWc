#include <stdio.h>

int main()
{
    int a = 0;
    int mas[] = {0, 1, 2, 3, 4, 5, 6, 7}; 
    a = mas[0];
    mas[0] = mas[7];
    mas[7] = a;
    printf("%d\n", mas[0]);
    printf("%d\n", mas[7]);
    return 0;
}