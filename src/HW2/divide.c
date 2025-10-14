#include <stdio.h>

int main()
{
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    int k = 0;
    int e = 1;
    if (b == 0){
        printf("%s\n", "не делите на 0");
        return 0;
    }
    if (a < 0){
        a = -a;
        e = e * -1;
    }
    if (b < 0){
        b = -b;
        e = e * -1;
    }
    while (a > 0)
        {
            k++;
            a = a - b;
        }
        if (a == 0 || e == -1){
            printf("%d\n", e*k);
        }
        else{
            printf("%d\n", e*k - 1);
        }
    return 0;
}