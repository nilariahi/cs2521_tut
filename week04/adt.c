// WARNING: this file will not compile

// Q1: use the Set ADT interface to implement the functions below.
// Creates a new empty set
Set SetNew(void);
// Frees memory allocated to the set
void SetFree(Set s);
// Inserts an element into the set
void SetInsert(Set s, int elem);
// Deletes an element from the set
void SetDelete(Set s, int elem);
// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem);
// Returns the number of elements in the set
int SetSize(Set s);

// This function takes an array of integers and its size, and returns 
// the number of integers that occur an odd number of times
// e.g. [4, 3, 4, 8, 8, 4] == 2
int numOddOccurrences(int arr[], int size) {
	Set s = SetNew();
	// go through ever number in arr
	// add it to the set on odd occurences (i.e. first time we see it, third time, etc.)
	// and remove it from the set on even occurences (i.e. second time we see it, fourth time, etc.)
	for (int i = 0; i < size; i++) {
		if (!SetContains(s, arr[i])) {
			SetInsert(s, arr[i]);
		} else {
			SetDelete(s, arr[i]);
		}
	}
	// whatever is still in the set must've been seen an odd number of times
	int ans = SetSize(s);
	SetFree(s);
	return ans;
}

// This function takes an array of integers and its size, and returns 
// the number of integers that occur exactly once.
// e.g. [4, 3, 4, 8, 7, 4] == 3
int numSingleOccurrences(int arr[], int size) {
	// use 2 sets to divide the array into 2 subsets
	// a) subset of numbers in arr that we've seen once
	// b) subset of numbers in arr that we've seen more than once
	Set once = SetNew();
	Set moreThanOnce = SetNew();
	// for each number in arr, if it's in the moreThanOnce set then do nothing
	// if it's not in the moreThanOnce set, check if it's in the once set
	// 		if it's in the once set, this must be the second time we've seen it
	//			so remove it from the once set and add it to moreThanOnce
	//		otherwise if it's not in the once set then this is the first time we've seen it!
	//			so add it to the once set
	for (int i = 0; i < size; i++) {
		if (!SetContains(moreThanOnce, arr[i])) {
			// check if it's been seen once
			if (SetContains(once, arr[i])) {
				SetDelete(one, arr[i]);
				SetInsert(moreThanOnce, arr[i]);
			} else {
				SetInsert(once, arr[i]);
			}
		} // else we've already seen it more than once, so do nothing
	}
	// all the numbers that occur exactly once must now be in the once set
	int ans = SetSize(once);
	SetFree(once);
	SetFree(moreThanOnce);
	return ans;
}

// Q2: use the following Stack ADT to implement a Queue
// Creates a new empty stack
Stack StackNew(void);
// Pushes an item onto the stack
void StackPush(Stack s, int item);
// Pops an item from the stack and returns it
// Assumes that the stack is not empty
int StackPop(Stack s);
// Returns the number of items on the stack
int StackSize(Stack s);

struct queue {
	Stack s1;
	Stack s2;
};

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

// O(1)
void QueueEnqueue(Queue q, int item) {
	// use s1 exclusively for enqueueing, so just push the item onto it
	StackPush(q->s1, item);
}

// Assumes that the queue is not empty, O(n)
int QueueDequeue(Queue q) {
	// use s2 exclusively for dequeueing
	// if it's not empty, whatever's at the top is the item we want to dequeue
	// so just pop it off and return it
	if (StackSize(q->s2) != 0) {
		return StackPop(s2);
	}

	// s2 was empty, so the item we need to dequeue must be at the bottom of the s1 stack
	// so pop everything off of s1 and push them onto s2 so that we get the reverse order
	while (StackSize(q->s1) != 0) {
		int value = StackPop(q->s1);
		StackPush(q->s2, value);
	}
	// s2 is now the reverse of what s1 used to be
	// so whatever was at the bottom of s1 is now at the top of s2
	// so we just pop it off and return it as our dequeued item
	return StackPop(q->s2);
}
