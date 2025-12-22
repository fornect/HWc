#include "sortList.h"
#include <stdio.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

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
        bool (*tests[7])() = { &testIsEmpty, &testOneElement, &testDeletionOneElement, &testDeletionManyStartElements, &testDeletionManyEndElements, &testDeletionManyMidleElements, &testDeletionAllElements };
        for (int testNum = 0; testNum < 7; ++testNum) {
            if (tests[testNum]()) {
                printf(GREEN("Test %d passed!\n"), testNum + 1);
            } else {
                printf(RED("Test %d failed!\n"), testNum + 1);
                return 1;
            }
        }
        return 0;
    }
    int a = 10;
    SortedList* list = newSortedList();
    printf("%s\n", "Имееться 4 команды: 0 - выйти, 1 – добавить значение в сортированный список, 2 – удалить значение из списка, 3 – распечатать список");
    while (a != 0) {
        printf("%s", "Введите команду:");
        scanf("%d", &a);
        int b = 0;
        if (a == 1) {
            printf("%s", "Введите значение:");
            scanf("%d", &b);
            push(list, b);
        } else if (a == 2) {
            printf("%s", "Введите значение:");
            scanf("%d", &b);
            deleteElement(list, b);
        } else if (a == 3) {
            printSortedList(list);
            printf("\n");
        } else if (a == 0) {
            deleteSortedList(list);
            return 0;
        } else {
            printf("%s", "нет такой команды");
        }
    }
    return 0;
}
