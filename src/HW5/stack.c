#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct CharStack {
    ListNode* head;
} CharStack;

CharStack* newStack()
{
    CharStack* stack = malloc(sizeof(*stack));
    stack->head = NULL;
    return stack;
}

int push(CharStack* stack, char value)
{
    if (stack == NULL)
        return -1;

    ListNode* newElement = malloc(sizeof(ListNode));
    if (newElement == NULL)
        return -2;
    newElement->value = value;
    newElement->next = stack->head;
    stack->head = newElement;
    return 0;
}

char pop(CharStack* stack)
{
    if (isEmpty(stack)) {
        return 'N';
    }
    char result = stack->head->value;
    ListNode* popElement = stack->head;
    stack->head = stack->head->next;
    free(popElement);
    return result;
}

char peek(CharStack* stack)
{
    if (isEmpty(stack))
    {
        return 'N';
    }
    return stack->head->value;
}

bool isEmpty(CharStack* stack)
{
    return (stack->head == NULL);
}