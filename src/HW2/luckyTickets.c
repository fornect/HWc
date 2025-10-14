#include <stdio.h>

int main()
{
    int k[28] = {};
    for (int i = 1; i <= 999; i++)
    {
        int sumc = (i % 10) + (i / 100) + (i % 100) / 10;
        k[sumc] = k[sumc] + 1;
    }
    int summ = 1;
    for (int i = 1; i <= 27; i++)
    {
        summ = summ + (k[i] * k[i]);
    }
    printf("%d\n", summ);
    return 0;
}