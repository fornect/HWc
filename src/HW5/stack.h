#pragma once
#include <stdbool.h>
// stack
typedef struct CharStack CharStack;

// coздание стека
CharStack* newStack();

// добавить на верх
int push(CharStack* stack, char value);

// взять значение верхнего и удалить его
// перед этой функцией всегда вызывать isEmpty()
char pop(CharStack* stack);

// взять значение верхнего
// перед этой функцией всегда вызывать isEmpty()
char peek(CharStack* stack);

//
bool isEmpty(CharStack* stack);
