#include <stdio.h>

// Q2 Explain why the swap() function here does not work as intended.
// Modify the code so that it works as intended.
// Show how the new version works using a diagram.
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void) {
    int a = 5;
    int b = 7;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}
