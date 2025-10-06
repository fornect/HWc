#include "sort_q.h"
#include <stdlib.h>

int compare_ints(const void* a, const void* b) 
{
    int int_a = *((const int*)a);
    int int_b = *((const int*)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}


void sort_q(int* mas, int lenm)
{
    qsort(mas, lenm, sizeof(int), compare_ints);
}


int matching(int* mas1, int* mas2, int lenmas)
{
    int q;
    int k = 0;
    for (q = 0; q < lenmas; q++){
        if (mas1[q] == mas2[q]){
            k++;
        }
    }
    return q-k;
}