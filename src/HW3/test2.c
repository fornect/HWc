#include <stdio.h>

int main() {
    int num;
    char str[50];

    printf("Введите число: ");
    scanf("%d", &num);

    // Очистка буфера после scanf
    while ((getchar()) != '\n'); 

    printf("Введите строку: ");
    scanf("%s", str);

    printf("Число: %d, Строка: %s\n", num, str);

    return 0;
}