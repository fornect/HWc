#include <stdbool.h>
#include <stdio.h>

bool divide(int a, int b, int* k)
{
    int e = 1;
    if (b == 0) {
        return false;
    }
    if (a < 0) {
        a = -a;
        e = e * -1;
    }
    if (b < 0) {
        b = -b;
        e = e * -1;
    }
    while (a > 0) {
        (*k)++;
        a = a - b;
    }
    if (a == 0 || e == -1) {
        *k = e * (*k);
    } else {
        *k = e * (*k) - 1;
    }
    return true;
}

int main()
{
    int a = 0;
    int b = 0;
    int k = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    if (divide(a, b, &k)) {
        printf("%d\n", k);
        return 0;
    }
    printf("%s\n", "не делите на 0");
    return 0;
}