#pragma once

// stack
typedef struct Node_tag 
{
        char value;
        struct Node_tag *next;
} charStack;

//добавить на верх
void push(charStack **head, char value);

//взять значение верхнего и удалить его
char pop(charStack **head);

//взять значение верхнего
char peek(const charStack* head);