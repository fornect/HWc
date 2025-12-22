#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct CharStack {
    ListNode* head;
} CharStack;

CharStack* newStack()
{
    CharStack* list = malloc(sizeof(*list));
    list->head = NULL;
    return list;
}

int push(CharStack* list, char value)
{
    if (list == NULL)
        return -1;

    ListNode* newElement = malloc(sizeof(ListNode));
    if (newElement == NULL)
        return -2;
    newElement->value = value;
    newElement->next = list->head;
    list->head = newElement;
    return 0;
}

char pop(CharStack* list)
{
    if (list->head == NULL) {
        return 'N';
    }
    char result = list->head->value;
    ListNode* popElement = list->head;
    list->head = list->head->next;
    free(popElement);
    return result;
}

char peek(CharStack* list)
{
    if (list->head == NULL)
    {
        return 'N';
    }
    return list->head->value;
}