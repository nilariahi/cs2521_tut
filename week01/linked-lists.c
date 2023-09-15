#include <stdio.h>
#include <stdlib.h>

// Q2: Write a function to sum the values in the list.
// Implement it first using while and then using for.
struct node {
	int value;
	struct node *next;
};
int listSum(struct node *head) {
    int sum = 0;
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}
// Bonus: listSum implemented recursively
int listRecSum(struct node *head) {
    // base case == simplest case
    if (head == NULL) {
        return 0;
    }

    // recursive case
    return head->value + listRecSum(head->next);
}


// Q3: Implement a function to delete the first instance of a value
// from a list, if it exists. Use the following list representation and prototype:
struct node {
    int value;
    struct node *next;
};
struct node *listDelete(struct node *list, int value) {
    if (list == NULL) return NULL; // empty list

    // value was at the head of the list
    if (list->value == value) {
        struct node *newHead = list->next;
        free(list);
        return newHead;
    }

    // middle or end
    struct node *prev = NULL;
    struct node *curr = list;
    while (curr != NULL) {
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            return list;
        }
        prev = curr;
        curr = curr->next;
    }
    // didn't find the value
    return list;
}

// How would the implementation and prototype be different if
// the following list representation was used instead?
struct node {
    int value;
    struct node *next;
};
struct list {
	struct node *head;
};
void listDelete(struct list *list, int value) {
    if (list->head == NULL) return; // empty list

    // value was at the head of the list
    if (list->head->value == value) {
        struct node *oldHead = list->head;
        list->head = list->head->next;
        free(oldHead);
        return;
    }

    // middle or end
    struct node *prev = NULL;
    struct node *curr = list->head;
    while (curr != NULL) {
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
