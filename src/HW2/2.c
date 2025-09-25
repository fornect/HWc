#include <stdio.h>

int main()
{
    int a = 20;
    int b = 3;
    int k = 0;
    if (b == 0)
    {
        printf("%s\n", "не делите на 0");
    }
    else if ((a >= 0) && (b > 0))
    {
        while (a > 0)
        {
            k = k + 1;
            a = a - b;
        }
        if (a == 0)
        {
            printf("%d\n", k);
        }
        else
        {
            printf("%d\n", k - 1);
        }
    }
    else if ((a < 0) && (b < 0))
    {
        int a = -a;
        int b = -b;
        while (a > 0)
        {
            int k = k + 1;
            a = a - b;
        }
        if (a == 0)
        {
            printf("%d\n", k);
        }
        else
        {
            printf("%d\n", k-1);
        }    
    }
    else if ((a > 0) && (b < 0))
    {
        int b = -b;
        while (a > 0)
        {
            int k = k + 1;
            a = a - b;
        }
        if (a == 0)
        {
            printf("%d\n", -k);
        }
        else
        {
            printf("%d\n", -k-1);
        }
    }
    else if ((a < 0) && (b > 0))
    {
        int a = -a;
        while (a > 0)
        {
            int k = k + 1;
            a = a - b;
        }
        if (a == 0)
        {
            printf("%d\n", -k);
        }
        else
        {
            printf("%d\n", -k-1);
        }
    }
    return 0;
}