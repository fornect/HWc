#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

// если a == b, выводим 0; если a > b, выводим 1; если a < b, выводим -1;
int comparison(bool* first, bool* second)
{
    int lenFirst = sizeof(*first) / sizeof(bool);
    int lenSecond = sizeof(*second) / sizeof(bool);
    int flagZnach = 0;
    while (lenSecond > 0 && lenFirst > 0) {
        if (first[lenFirst - 1] > second[lenSecond - 1]) {
            flagZnach = 1;
        }
        if (first[lenFirst - 1] < second[lenSecond - 1]) {
            flagZnach = -1;
        }
        lenFirst--;
        lenSecond--;
    }
    while(lenFirst > 0){
        if (first[lenFirst - 1] == true){
            return 1;
        }
        lenFirst--;
    }
    while(lenSecond > 0){
        if (first[lenSecond - 1] == true){
            return -1;
        }
        lenSecond--;
    }

    return flagZnach;
}

bool testLess()
{
    bool a[1] = {false};
    bool b[1] = {true};
    if (comparison(a,b) == -1){
        return true;
    }
    return false;
}
bool testMore()
{
    bool a[1] = {true};
    bool b[1] = {false};
    if (comparison(a,b) == 1){
        return true;
    }
    return false;
}
bool testEqually()
{
    bool a[1] = {true};
    bool b[1] = {true};
    if (comparison(a,b) == 0){
        return true;
    }
    return false;
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
        bool (*tests[3])() = { &testLess, &testMore, &testEqually };
        for (int testNum = 0; testNum < 3; ++testNum) {
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