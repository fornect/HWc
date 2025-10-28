#include <stdlib.h>
#include <stdio.h>


typedef struct ListNode{
  int value;
  struct ListNode* prev;
  struct ListNode* next;
}ListNode;

typedef struct List{
    ListNode* head;
    ListNode* tail;
}List;

List new()
{
    List list = { .head = NULL , .tail = NULL};
    return list;
}

int push(List* list, int value)
{
  if (list == NULL) return -1;

  ListNode* new = malloc(sizeof(ListNode));
  if (new == NULL) return -2;

  new->prev = new->next = NULL;
  new->value = value;
  
  if (list->head)
  {
    list->head->prev = new;
    new->next = list->head;
    list->head = new;
  }
  else 
  {
    list->head = list->tail = new;
  }
  ListNode* current = list->head;
  while (current && current->next)
  {
    if (current->value < current->next->value)
    {
    int val = current->value;
    current->value = current->next->value;
    current->next->value = val;
    }
    current = current->next;
  }
  return 0;
}

void printList(List* list)
{
  ListNode* current = list->head;

  while (current)
  {
    printf("%d ", current->value);
    current = current->next;
  }
}

int delElement(List* list, int value)
{
  ListNode* current = list->head;
  while (current)
  {
    if (current->value == value)
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      current = current->next;
    }
    else
    {
      current = current->next;
    }
  }
}


int main()
{
    int a = 10;
    List list = new();
    printf("%s\n", "Имееться 4 команды: 0 - выйти, 1 – добавить значение в сортированный список, 2 – удалить значение из списка, 3 – распечатать список");
    while (a != 0){
        printf("%s", "Введите команду:");
        scanf("%d", &a);
        if(a == 1){
            int b;
            printf("%s", "Введите значение:");
            scanf("%d", &b);
            push(&list, b);
        }
        else if(a == 2){
            int b;
            printf("%s", "Введите значение:");
            scanf("%d", &b);
            delElement(&list, b);
        }
        else if(a == 3){
            printList(&list);
            printf("\n");
        }
        else if(a == 0){
            return 0;
        }
        else{
            printf("%s", "нет такой команды");
        }
    }
    return 0;
}