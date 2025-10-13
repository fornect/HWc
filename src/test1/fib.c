#include <stdio.h>

int main(void)
{
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int c;
    unsigned int sumfib;
    int i;
    for (i = 0; i<=999999; i++){
        c = a + b;
        if (a % 2 == 0){
            sumfib = sumfib + a;
        }
        if (i == 999999){
            printf("%d", a);
        }
        a = b;
        b = c;
    }
    //printf("%d", sumfib);
    return 0;
}