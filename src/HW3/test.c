#include <stdio.h>

int main()
{
    int len;
    char strq[len+1];
    printf("введите длину строки:");
    scanf("%d", &len);
    printf("введите вашу строку:");
    fgets(strq, sizeof(strq) ,stdin);
    printf("%c\n", strq[15]);
    printf("%s\n", strq);
    return 0;
}