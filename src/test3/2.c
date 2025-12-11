#include "bubbleSort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

// чтобы скомпилировать используйте gcc bubbleSort.c 2.c и поставте все необходимые флаги. После запустите с флагом --test
int count_digits(int n)
{
    if (n == 0) {
        return 1;
    }
    int count = 0;
    if (n < 0) {
        n = -n;
    }
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

int lowest(unsigned num)
{
    int result = 0;
    int lenNum = count_digits(num);
    char buffer[lenNum];
    sprintf(buffer, "%d", num);
    int* notSortArr = (int*)malloc(lenNum * sizeof(int));
    for (int i = 0; i < lenNum; i++) {
        notSortArr[i] = buffer[i] - '0';
    }
    int* sortArr = (int*)malloc(lenNum * sizeof(int));
    memcpy(sortArr, notSortArr, lenNum * sizeof(int));
    bubbleSort(sortArr, lenNum);
    int powTen = 1;
    for (int i = lenNum - 1; i >= 0; i--) {
        result = result + sortArr[i] * powTen;
        powTen = powTen * 10;
    }
    return result;
}
bool testSame()
{
    return lowest(111111) == 111111;
}
bool testZero()
{
    return lowest(0) == 0;
}
bool testNormal()
{
    return lowest(542618) == 124568;
}
bool testMuchZero()
{
    return lowest(100000) == 1;
}

int main(int argc, char** argv)
{
    bool testMode = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--test") == 0) {
            testMode = true;
            break;
        }
    }
    if (testMode) {
        bool (*tests[4])() = { &testSame, &testZero, &testNormal, &testMuchZero };
        for (int testNum = 0; testNum < 4; ++testNum) {
            if (tests[testNum]()) {
                printf(GREEN("Test %d passed!\n"), testNum + 1);
            } else {
                printf(RED("Test %d failed!\n"), testNum + 1);
                return 1;
            }
        }
        return 0;
    }
}