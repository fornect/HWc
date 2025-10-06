#include <stdio.h>

int main()
{
    int i;
    int n;
    int k;
    printf("введите количество элементов массива:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i<n; i++)
    {
        if (a[i] == 0)
        {
            k++;
        }
    }
    printf("%d\n", k);
    return 0;
}