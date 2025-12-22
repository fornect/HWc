#pragma once
#include <stdbool.h>

// sorted list
typedef struct SortedList SortedList;

// return empty list
SortedList* newSortedList();

// push element to list and sort list
// if return 0 all good; if return -1 or -2 not good
int push(SortedList* list, int value);

// return sorted list
void printSortedList(SortedList* list);

// return sorted list without deleted element
int deleteElement(SortedList* list, int value);

// print sorted list to konsole
void printSortedList(SortedList* list);

// return empty list
void deleteSortedList(SortedList* list);

// check empty list
bool isEmpty(SortedList* list);

// tests
bool testIsEmpty();

bool testOneElement();

bool testDeletionOneElement();

bool testDeletionManyStartElements();

bool testDeletionManyEndElements();

bool testDeletionManyMidleElements();

bool testDeletionAllElements();
