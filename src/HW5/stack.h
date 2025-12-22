#pragma once
#include <stdbool.h>
// stack
typedef struct CharStack CharStack;

// coздание стека
CharStack* newStack();

<<<<<<< HEAD
<<<<<<< HEAD
// добавить на верх
=======
//добавить на верх
>>>>>>> 0ee0d90 (mini fix)
=======
// добавить на верх
>>>>>>> 339261d (all fix)
int push(CharStack* stack, char value);

// взять значение верхнего и удалить его
// перед этой функцией всегда вызывать isEmpty()
char pop(CharStack* stack);

// взять значение верхнего
// перед этой функцией всегда вызывать isEmpty()
char peek(CharStack* stack);

//
<<<<<<< HEAD
<<<<<<< HEAD
bool isEmpty(CharStack* stack);
=======
bool isEmpty(CharStack *stack);
>>>>>>> 0ee0d90 (mini fix)
=======
bool isEmpty(CharStack* stack);
>>>>>>> 339261d (all fix)
