#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for Q1-5
struct node {
	int value;
	struct node *next;
};

// Q1: compute the length of a linked list
int listLength(struct node *l);

// Q2: count the number of odd numbers in a linked list
int listCountOdds(struct node *l);

// Q3: check whether a list is sorted in ascending order
bool listIsSorted(struct node *l);

// Q4: delete the first instance of a value from a linked list
struct node *listDelete(struct node *l, int value);

// Q5: How would your recursive solutions for the above questions change
// if the functions took a struct list pointer instead of a node pointer
struct list {
	struct node *head;
};
int listLength2(struct list *l);

// Bonus: computes x^n where n is non-negative
// currently O(n), optimise this so that it's O(log n)
int myPow(int x, unsigned int n);
