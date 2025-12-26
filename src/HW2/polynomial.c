#include <stdio.h>

int main()
{
    int x = 0;
    scanf("%d", &x);
    int t = x * x;
    int polynomial = (t + 1) * (t + x) + 1;
    printf("%d\n", polynomial);
    return 0;
}