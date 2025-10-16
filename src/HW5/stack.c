#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(charStack **head, char value)
{
    charStack *tmp = malloc(sizeof(charStack));
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}

char pop(charStack **head)
{
        charStack *out;
        char value;
        if (*head == NULL) {
                return 'N';
        }
        out = *head;
        *head = (*head)->next;
        value = out->value;
        free(out);
        return value;
}

char peek(const charStack* head)
{
        if (head == NULL) {
                return 'N';
        }
        return head->value;
}