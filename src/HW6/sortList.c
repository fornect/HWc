#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct SortedList {
    ListNode* head;
} SortedList;

SortedList* newSortedList()
{
    SortedList* list = malloc(sizeof(*list));
    list->head = NULL;
    return list;
}

int push(SortedList* list, int value)
{
    if (list == NULL)
        return -1;

    ListNode* newElement = malloc(sizeof(ListNode));
    if (newElement == NULL)
        return -2;
    newElement->value = value;
    newElement->next = list->head;
    list->head = newElement;
    ListNode* current = list->head;
    while (current != NULL && current->next != NULL) {
        if (current->value < current->next->value) {
            int val = current->value;
            current->value = current->next->value;
            current->next->value = val;
        }
        current = current->next;
    }
    return 0;
}

void printSortedList(SortedList* list)
{
    ListNode* current = list->head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

void deleteElement(SortedList* list, int value)
{
    ListNode* current = list->head;
    ListNode* currentPrev = list->head;
    while (current != NULL) {
        if (current->value == value) {
            if (current->next == NULL && current == list->head) {
                list->head = NULL;
                free(current);
                break;
            } else if (current->next == NULL) {
                currentPrev->next = NULL;
                free(current);
                break;
            } else if (current == list->head) {
                list->head = list->head->next;
                free(current);
                current = list->head;
                currentPrev = current;
            } else {
                currentPrev->next = current->next;
                free(current);
                current = currentPrev;
                current = current->next;
            }
        } else {
            currentPrev = current;
            current = current->next;
        }
    }
}
void deleteSortedList(SortedList* list)
{
    ListNode* current = list->head;
    if (list->head != NULL) {
        while (current->next != NULL) {
            list->head = current->next;
            free(current);
            current = list->head;
        }
        list->head = NULL;
        free(current);
    }
    free(list);
}

bool isEmpty(SortedList* list)
{
    return list->head == NULL;
}

bool testIsEmpty()
{
    SortedList* list = newSortedList();
    bool result = isEmpty(list);
    free(list);
    return result;
}

bool testOneElement()
{
    SortedList* list = newSortedList();
    push(list, 1);
    bool result = (list->head->value == 1);
    deleteSortedList(list);
    return result;
}

bool testDeletionOneElement()
{
    SortedList* list = newSortedList();
    push(list, 1);
    deleteElement(list, 1);
    return isEmpty(list);
}

bool testDeletionManyStartElements()
{
    SortedList* list = newSortedList();
    for (int i = 0; i < 10; i++) {
        push(list, 2);
    }
    push(list, 1);
    deleteElement(list, 2);
    bool result = (list->head->value == 1);
    deleteSortedList(list);
    return result;
}
bool testDeletionManyEndElements()
{
    SortedList* list = newSortedList();
    for (int i = 0; i < 10; i++) {
        push(list, 2);
    }
    push(list, 3);
    deleteElement(list, 2);
    bool result = (list->head->next == NULL);
    deleteSortedList(list);
    return result;
}
bool testDeletionManyMidleElements()
{
    SortedList* list = newSortedList();
    for (int i = 0; i < 10; i++) {
        push(list, 2);
    }
    push(list, 3);
    push(list, 1);
    deleteElement(list, 2);
    bool result = (list->head->next->value == 1);
    deleteSortedList(list);
    return result;
}
bool testDeletionAllElements()
{
    SortedList* list = newSortedList();
    for (int i = 0; i < 10; i++) {
        push(list, 2);
    }
    push(list, 3);
    push(list, 1);
    deleteSortedList(list);
    return isEmpty(list);
}
