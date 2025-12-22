#pragma once
#include <stdbool.h>
// stack
typedef struct CharStack CharStack;

//добавить на верх
int push(CharStack* stack, char value);

//взять значение верхнего и удалить его
char pop(CharStack *stack);

//взять значение верхнего
char peek(CharStack *stack);

//
bool isEmpty(CharStack *stack);