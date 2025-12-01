#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// короче должно было быть 2 стека один из них должен был заполняться 
// другой отполняться когда второй заканчивался то из первого просто пополось 
// во второй и все прекрасно!!!
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
} List;


List new()
{
    List list = {.head = NULL};
    return list;
}

void push1(List* list, char value)
{
    ListNode* new = malloc(sizeof(ListNode));
    if (new == NULL) {
        exit(-100);
    }
    new->next = NULL;
    new->value = value;
}

char pop1(Node_t1** head)
{
    Node_t1* out;
    char value;
    if (*head == NULL) {
        exit(-101);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}

void push(char value)
{
    push1(st1, )
}

int main(int argc, char** argv)
{
    bool testMode = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--test") == 0) {
            testMode = true;
            break;
        }
    }

    if (testMode) {
        bool (*tests[3])() = { &testLess, &testMore, &testEqually };
        for (int testNum = 0; testNum < 3; ++testNum) {
            if (tests[testNum]()) {
                printf(GREEN("Test %d passed!\n"), testNum + 1);
            } else {
                printf(RED("Test %d failed!\n"), testNum + 1);
                return 1;
            }
        }
        return 0;
    }
}
