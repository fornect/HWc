#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort_q.h"

int main()
{
    int lenmas;
    int sortmas[101];
    int notsortmas[101];
    int i;
    int n;
    int j;
    printf("Введите числа через пробел, нажмите ENTER чтобы прекратить ввод:");
    for (i = 0; i < 101; i++) {
        scanf("%d", &notsortmas[i]);
        if (getchar() == '\n'){
            break;
        }
    }
    memcpy(sortmas, notsortmas, sizeof(notsortmas));
    i++;
    sort_q(sortmas, i);
    printf("%d\n", matching(notsortmas, sortmas, i));
}