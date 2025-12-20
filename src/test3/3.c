#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"
// чтобы скомпилировать используйте gcc 3.c и поставте все необходимые флаги. После запустите с флагом --test
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
} List;

List new()
{
    List list = { .head = NULL };
    return list;
}

int push(List* list, int value)
{
    if (list == NULL)
        return -1;

    ListNode* new = malloc(sizeof(ListNode));
    if (new == NULL)
        return -2;

    new->next = NULL;
    new->value = value;

    if (list->head) {
        new->next = list->head;
        list->head = new;
    } else {
        list->head = new;
    }
    return 0;
}

void printList(List* list)
{
    ListNode* current = list->head;

    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

List reversListE(List* list1)
{
    List list2 = new();
    ListNode* newEl = list1->head;
    while (newEl) {
        push(&list2, newEl->value);
        newEl = newEl->next;
    }
    return list2;
}
bool testVoid()
{
    List list1 = new();
    List list2 = reversListE(&list1);
    return list2.head == NULL;
}

bool testOne()
{
    List list1 = new();
    push(&list1, 4);
    List list2 = reversListE(&list1);
    return list2.head->value == 4;
}

bool testNormal()
{
    List list1 = new();
    push(&list1, 4);
    push(&list1, 7);
    push(&list1, 3);
    List list2 = reversListE(&list1);
    return list1.head->value == list2.head->next->next->value;
}

bool testSame()
{
    List list1 = new();
    push(&list1, 4);
    push(&list1, 4);
    push(&list1, 4);
    push(&list1, 4);
    List list2 = reversListE(&list1);
    return ((list2.head->value == list2.head->next->value) && (list2.head->next->next->value == list2.head->next->next->next->value));
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
        bool (*tests[4])() = { &testVoid, &testOne, &testNormal, &testSame };
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