#include <stdio.h>

int main()
{
    int x = 2;
    int t = x * x;
    printf("%d\n",(t + 1) * (t + x) + 1);
    return 0;
}