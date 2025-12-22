#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct KnightList {
    ListNode* head;
} KnightList;

KnightList new()
{
    KnightList list = { NULL };
    return list;
}

int push(KnightList* list, int value)
{
    if (list == NULL)
        return -1;

    ListNode* new = malloc(sizeof(ListNode));
    if (new == NULL)
        return -2;
    new->value = value;
    new->next = list->head;
    list->head = new;
    return 0;
}
void cyclingList(KnightList* list)
{
    ListNode* current = list->head;
    if (current != NULL) {
        while (current->next != NULL) {
            if (current->next == list->head) {
                break;
            }
            current = current->next;
        }
        current->next = list->head;
    }
}

void deleteElement(KnightList* list, int value)
{
    ListNode* current = list->head;
    ListNode* currentForDelete = NULL;
    while (current->next->value != value) {
        current = current->next;
        if (current->next == list->head) {
            break;
        }
    }
    if (current->next == list->head) {
        currentForDelete = list->head;
        list->head = current;
        current->next = current->next->next;
    } else if (current == current->next) {
        list->head = NULL;
    } else {
        currentForDelete = current->next;
        current->next = current->next->next;
    }

    free(currentForDelete);
}

bool isEmpty(KnightList* list)
{
    return list->head == NULL;
}

void knight(KnightList* list, int countKnight)
{
    for (int i = countKnight; 0 < i; i--) {
        push(list, i);
    }
    cyclingList(list);
}

int killKnight(KnightList* list, int knight)
{
    ListNode* current = list->head;
    while (current != current->next) {
        for (int i = 1; i < knight; i++) {
            current = current->next;
        }
        int numKnight = current->value;
        current = current->next;
        deleteElement(list, numKnight);
    }
    int numKnight = current->value;
    deleteElement(list, numKnight);
    return numKnight;
}

int megaKill(int countKnight, int kill)
{
    KnightList list = new();
    knight(&list, countKnight);
    int result = killKnight(&list, kill);
    return result;
}
int main()
{
    int countKnight = 0;
    int kill = 0;
    printf("%s", "Введите количество воинов:");
    scanf("%d", &countKnight);
    printf("%s", "Введите какого по счету воина будут убивать:");
    scanf("%d", &kill);
    if (countKnight < 1) {
        printf("%s", "воинов недостаточно для убийства");
        printf("\n");
        return 0;
    }
    if (kill == 0) {
        printf("%s", "ни кого не убивать не выйдет");
        printf("\n");
        return 0;
    }
    if (kill < 0) {
        printf("%s", "воскрешение запрешенно!!!");
        printf("\n");
        return 0;
    }
    printf("%d\n", megaKill(countKnight, kill));
    return 0;
}