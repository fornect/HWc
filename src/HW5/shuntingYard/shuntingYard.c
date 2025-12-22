#include "../stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool isOperand(char element)
{
    if ((element == '+') || (element == '-') || (element == '*') || (element == '/')) {
        return true;
    }
    return false;
}
int operandPriority(char element)
{
    if ((element == '+') || (element == '-')) {
        return 1;
    } else if ((element == '/') || (element == '*')) {
        return 2;
    }
    return 0;
}
char* result(char* stringYard)
{
    int lenstring = strlen(stringYard);

    char* arr = malloc(sizeof(char) * 100);
    int lenexit = 0;
    CharStack* stack = newStack();
    for (int i = 0; i < lenstring; i++) {
        if (stringYard[i] != ' ') {
            if (isOperand(stringYard[i])) {
                if (!isEmpty(stack) && (operandPriority(peek(stack)) > operandPriority(stringYard[i]))) {
                    arr[lenexit] = pop(stack);
                }
                lenexit++;
                push(stack, stringYard[i]);
            } else if (stringYard[i] == '(') {
                push(stack, '(');
            } else if (!isEmpty(stack) && stringYard[i] == ')') {
                while (!isEmpty(stack) && peek(stack) != '(') {
                    arr[lenexit] = pop(stack);
                    lenexit++;
                }
                if (!isEmpty(stack)) {
                    pop(stack);
                }

            } else {
                arr[lenexit] = stringYard[i];
                lenexit++;
            }
        }
    }

    while (!isEmpty(stack)) {
        arr[lenexit] = pop(stack);
        lenexit++;
    }
    return arr;
}

int main()
{

    char stringYard[50];
    printf("Введите выражение\n");
    if (scanf("%49[^\n]", stringYard) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }
    char* arr = result(stringYard);
    int lenexit = sizeof(arr);
    for (int i = 0; i < lenexit; i++) {
        printf("%c ", arr[i]);
    }
    return 0;
}