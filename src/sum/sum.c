#include <stdio.h>
#include <stdlib.h>

int* binar(int n)
{
    int* binary = calloc(8, sizeof(int));
    int i = 7;
    if (n < 0) {
        n = (1 << 8) + n;
    }
    while (n > 0 && i >= 0) {
        binary[i] = n % 2;
        n = n / 2;
        i--;
    }
    return binary;
}

int dec(int *n){
    int value = 0;
    if (n[0] == 1){
        value = -128;
    }
    for(int i = 1; i < 8; i++){
        if (n[i] == 1){
            value = value + (1 << (7-i));
        }
    }
    return value;
}

int* sumbin(int* a, int* b)
{
    int* binary = calloc(8, sizeof(int));
    int k = 0;
    for (int i = 7; i >= 0; i--) {
        binary[i] = a[i] + b[i] + k;
        k = 0;
        if (binary[i] >= 2) {
            binary[i]--;
            binary[i]--;
            k = 1;
        }
    }
    return binary;
}

int main()
{
    int a = 0;
    int b = 0;
    int k = 0;
    printf("%s", "Введите первое число:");
    scanf("%d", &a);
    printf("%s", "Введите первое число:");
    scanf("%d", &b);
    if (63 < a || a < -63) {
        printf("%s", "складываем только маленькие");
        return 0;
    }
    if (63 < b || b < -63) {
        printf("%s", "складываем только маленькие");
        return 0;
    }
    int* abin = binar(a);
    printf("%s", "Первое число в двоичной записи:");
    for (int i = 0; i < 8; i++) {
        printf("%d", abin[i]);
    }
    int* bbin = binar(b);
    printf("\n%s", "Второе число в двоичной записи:");
    for (int i = 0; i < 8; i++) {
        printf("%d", bbin[i]);
    }

    int* sumab = sumbin(abin, bbin);
    printf("\n%s", "сумма в двоичной записи:");
    for (int i = 0; i < 8; i++) {
        printf("%d", sumab[i]);
    }
    printf("\n%s", "сумма в десятичной записи:");
    printf("%d", dec(sumab));
    return 0;
}