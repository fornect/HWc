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
    list->head->prev = list->tail;
    list->tail->next = list->head;
  }
  else 
  {
    list->head = list->tail = new;
    list->head->next = list->tail;
    list->tail->prev = list->head;
  }
}
int delElement(List* list, int co)
{
  ListNode* current = list->head;
  int k = 1;
  while (current->next != current)
  {
    if (k % co == 0)
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      //printf("%d", current->value);
    }
    k++;
    current = current->next;
    
  }
  printf("%d", current->value);
}

void printList(List* list, int n)
{
  ListNode* current = list->head;

  for (int i = 0; i < n; i++)
  {
    printf("%d ", current->value);
    current = current->next;
  }
}

int main()
{
  int countKnight;
  int kill;
  
  List list = new();
  printf("%s", "Введите количество воинов:");
  scanf("%d", &countKnight);
  printf("%s", "Введите какого по счету воина будут убивать:");
  scanf("%d", &kill);
  if (countKnight < 1){
    printf("%s", "воинов недостаточно для убийства");
    printf("\n");
    return 0;
  }
  for (int i = countKnight; 0 < i; i--){
    push(&list, i);
  }
  delElement(&list, kill);
  printf("\n");
  return 0;
}