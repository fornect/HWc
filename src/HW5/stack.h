#pragma once

// stack
typedef struct CharStack CharStack;

//добавить на верх
int push(CharStack* list, char value);

//взять значение верхнего и удалить его
char pop(CharStack *list);

//взять значение верхнего
char peek(CharStack *list);