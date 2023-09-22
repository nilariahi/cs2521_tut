#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursion.h"

#define SORTED 0
#define REVERSE 1

// helper functions for creating and freeing linked lists
static struct node *listCreate(int numNodes, int order, int n);
static void listFree(struct node *list);
static void listPrint(struct node *list);

// make file to demo the recursion functions for tut2
// no need to fully understand how this works but you
// may be interested in the helper func implementations
int main(int argc, char **argv) {
	// command line arg handing
	if (argc < 2) {
		fprintf(stderr, "Correct usage: %s <qnum>\n", argv[0]);
		return 1;
	}
	int qn = atoi(argv[1]);

	// create 3 sample lists for demo
	struct node *l1 = listCreate(0, SORTED, 1);
	struct node *l2 = listCreate(5, SORTED, 1);
	struct node *l3 = listCreate(7, REVERSE, 7);
	printf("l1 :: "); listPrint(l1);
	printf("l2 :: "); listPrint(l2);
	printf("l3 :: "); listPrint(l3);
	printf("---------------------------------------------------\n");

	// set up some variables to be used for demo
	switch (qn) {
		case 1:
			printf("listLength(l1) = %d\n", listLength(l1));
			printf("listLength(l2) = %d\n", listLength(l2));
			printf("listLength(l3) = %d\n", listLength(l3));
			break;
		case 2:
			printf("listCountOdds(l1) = %d\n", listCountOdds(l1));
			printf("listCountOdds(l2) = %d\n", listCountOdds(l2));
			printf("listCountOdds(l3) = %d\n", listCountOdds(l3));
			break;
		case 3:
			printf("listIsSorted(l1) = %s\n", listIsSorted(l1) == 1 ? "true" : "false");
			printf("listIsSorted(l2) = %s\n", listIsSorted(l2) == 1 ? "true" : "false");
			printf("listIsSorted(l3) = %s\n", listIsSorted(l3) == 1 ? "true" : "false");
			break;
		case 4:
			l1 = listDelete(l1, 10);
			l2 = listDelete(l2, 1);
			l3 = listDelete(l3, 3);
			printf("listDelete(l1, 10) = "); listPrint(l1);
			printf("listDelete(l2, 1) = "); listPrint(l2);
			printf("listDelete(l3, 3) = "); listPrint(l3);
			break;
		case 5:;
			struct list *listRep1 = malloc(sizeof(struct list));
			struct list *listRep2 = malloc(sizeof(struct list));
			struct list *listRep3 = malloc(sizeof(struct list));
			listRep1->head = l1;
			listRep2->head = l2;
			listRep3->head = l3;
			printf("listLength(listRep1) = %d\n", listLength2(listRep1));
			printf("listLength(listRep2) = %d\n", listLength2(listRep2));
			printf("listLength(listRep3) = %d\n", listLength2(listRep3));
			free(listRep1);
			free(listRep2);
			free(listRep3);
			break;
		default:
			fprintf(stderr, "Question number invalid, must be 1 to 5\n");
			return 1;
	}

	// clean up
	listFree(l1); listFree(l2); listFree(l3);
}

// create a linked list for demo purposes
static struct node *listCreate(int numNodes, int order, int n) {
	if (order == SORTED && n > numNodes) {
		return NULL;
	}
	else if (order == REVERSE && n <= 0) return NULL;

	struct node *list = malloc(sizeof(struct node));
	list->value = n;
	n = (order == SORTED) ? n + 1 : n - 1;
	list->next = listCreate(numNodes, order, n);
	return list;
}

// free linked list
static void listFree(struct node *list) {
	if (list == NULL) return;

	listFree(list->next);
	free(list);
}

// print linked list
static void listPrint(struct node *list) {
	if (list == NULL) {
		printf("NULL\n");
		return;
	};

	printf("%d -> ", list->value);
	listPrint(list->next);
}
