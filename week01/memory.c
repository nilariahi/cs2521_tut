#include <stdio.h>

// Q3: Modify the code below so that it allocates 
// the struct on the heap, instead of the stack.
struct node {
	int value;
	struct node *next;
};
int main(void) {
	struct node *n = malloc(sizeof(struct node));
	n->value = 42;
	n->next = NULL;
	// NOTE: this creates a memory leak
	// since n is never freed
}

// Q4: The following code creates an array of 5 integers
// on the stack and uses it to store some values.
// How can you allocate the array on the heap instead?
int main(void) {
	int *a = malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++) {
		a[i] = 42;
	}
	// NOTE: this creates a memory leak
}
