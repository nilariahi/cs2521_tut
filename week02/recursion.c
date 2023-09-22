#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "recursion.h"

// Q1: compute the length of a linked list
int listLength(struct node *l) {
	// base case
	if (l == NULL) {
		return 0;
	}

	// recursive case
	return 1 + listLength(l->next);
}

// Q2: count the number of odd numbers in a linked list
int listCountOdds(struct node *l) {
	if (l == NULL) {
		return 0;
	}

	if (l->value % 2 == 0) {
		return 0 + listCountOdds(l->next);
	}
	
	return 1 + listCountOdds(l->next);
}

// Q3: check whether a list is sorted in ascending order
bool listIsSorted(struct node *l) {
	// empty list
	if (!l) { // same as l == NULL
		return true;
	}
	// single item list
	if (l->next == NULL) {
		return true;
	}
	// first two elements are out of order
	if (l->next->value < l->value) return false;

	// first two elements are fine, check the rest of the list
	return listIsSorted(l->next);
}

// Q4: delete the first instance of a value from a linked list
struct node *listDelete(struct node *l, int value) {
	if (l == NULL) return NULL;

	if (l->value == value) {
		struct node *rest = l->next;
		free(l);
		return rest;
	}

	l->next = listDelete(l->next, value);
	return l;
}

// Q5: How would your recursive solutions for the above questions change
// if the functions took a struct list pointer instead of a node pointer
int listLength2(struct list *l) {
	// struct list is a wrapper around the actual nodes in the linked list
	// need to call a helper function that takes a struct node *
	// and solves the problem recursively
	return listLength(l->head);
}

// Bonus: computes x^n where n is non-negative
// currently O(n), optimise this so that it's O(log n)
// must be a recursive solution
int myPow(int x, unsigned int n) {
	// Let's look at a few examples of powers of x:
	// x^4 = pow(x^2, 2)
	// x^5 = x * x^4 = x * pow(x^2, 2)
	// x^6 -> pow(x^2, 3)
	// We can observe that
	// x^n = pow(x^2, n/2) if n is even, and
	// x^n = x * pow(n^2, n/2) if n is off
	// Knowing this, we can implement this function recursively
	// bases cases are x^0 and x^1
	if (n == 0) return 1;
	if (n == 1) return x;

	// use the relationship we established above for recursive cases
	if (n % 2 == 0) { // n is even
		return myPow(x * x, n / 2);
	} else {
		return x * myPow(x * x, n / 2); // n is odd
	}

	// The recursive solution is O(log n)
	// because the input size n gets halved everytime
	// we recurse, which means that this function
	// gets called log n times before we hit a base case

	// original O(n) iterative solution
	// int res = 1;
	// for (int i = 1; i <= n; i++) {
	// 	res = res * x;
	// }
	// return res;
}
