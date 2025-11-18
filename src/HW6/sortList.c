#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

typedef struct ListNode {
    int value;
    struct ListNode* prev;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    ListNode* tail;
} List;

List new()
{
    List list = { .head = NULL, .tail = NULL };
    return list;
}

int push(List* list, int value)
{
    if (list == NULL)
        return -1;

    ListNode* new = malloc(sizeof(ListNode));
    if (new == NULL)
        return -2;

    new->prev = new->next = NULL;
    new->value = value;

    if (list->head) {
        list->head->prev = new;
        new->next = list->head;
        list->head = new;
    } else {
        list->head = list->tail = new;
    }
    ListNode* current = list->head;
    while (current && current->next) {
        if (current->value < current->next->value) {
            int val = current->value;
            current->value = current->next->value;
            current->next->value = val;
        }
        current = current->next;
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
}

int delElement(List* list, int value)
{
    ListNode* current = list->head;
    while (current != NULL) {
        if (current->value == value) {
            if (current->prev == NULL && current->next == NULL) {
                list->head = NULL;
                list->tail = NULL;
            } else if (current->prev == NULL) {
                current->next->prev = NULL;
                list->head = current->next;
            } else if (current->next == NULL) {
                current->prev->next = NULL;
                list->tail = current->prev;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
        }
        current = current->next;
    }
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

bool testIsEmpty()
{
    List list = new();
    return isEmpty(&list);
}

bool testOneElement()
{
    List list = new();
    push(&list, 1);
    return !isEmpty(&list);
}

bool testDeletion()
{
    List list = new();
    push(&list, 1);
    delElement(&list, 1);
    return isEmpty(&list);
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
        bool (*tests[3])() = { &testIsEmpty, &testOneElement, &testDeletion };
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
    int a = 10;
    List list = new();
    printf("%s\n", "Имееться 4 команды: 0 - выйти, 1 – добавить значение в сортированный список, 2 – удалить значение из списка, 3 – распечатать список");
    while (a != 0) {
        printf("%s", "Введите команду:");
        scanf("%d", &a);
        if (a == 1) {
            int b;
            printf("%s", "Введите значение:");
            scanf("%d", &b);
            push(&list, b);
        } else if (a == 2) {
            int b;
            printf("%s", "Введите значение:");
            scanf("%d", &b);
            delElement(&list, b);
        } else if (a == 3) {
            printList(&list);
            printf("\n");
        } else if (a == 0) {
            return 0;
        } else {
            printf("%s", "нет такой команды");
        }
    }
    return 0;
}