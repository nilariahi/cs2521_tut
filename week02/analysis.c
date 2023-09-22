#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Q1: Determine if a string of length n is a palindrome
/* Algorithm: 
palindrome():
	Input: string s of length n
	Output: true if s is a palindrome, else false

	let i = 0
	while i < n / 2 do
		s[i] != s[n - i - 1] return false
		i = i + 1
	return true
	
*/
// Worst-case time complexity: O(n)
// Implementation
bool palindrome(char *s) {
	int n = strlen(s);
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) return false;
	}
	return true;
}

// Q2: Determine if an array contains two elements
// that sum to a given value
/* Algorithm: 
hasTwoSum():
	Input: array A of size n, integer value
	Outpu: true if 2 distinct values in A sum to value, else false

	for i = 0 up to n - 1 do // O(n)
		for j = i + 1 up to n - 1 do
			if a[i] + a[j] == value then 
				return true
	return false
	
*/
// Worst-case time complexity: O(n^2)
// Implementation
bool hasTwoSum(int *A, int n, int value) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[i] + A[j] == value)
				return true;
		}
	}
	return false;
}

// try a few small test cases
int main(void) {
	printf("palindrome(\"racecar\") == %s\n", 
		palindrome("racecar") == 1 ? "true" : "false");
	printf("palindrome(\"reviewer\") == %s\n", 
		palindrome("reviewer") == 1 ? "true" : "false");
	int arr[5] = {1, 2, 3, 4, 5};
	printf("hasTwoSum([1,2,3,4,5], 5, 6) == %s\n", 
		hasTwoSum(arr, 5, 6) == 1 ? "true" : "false");
	printf("hasTwoSum([1,2,3,4,5], 5, 10) == %s\n", 
		hasTwoSum(arr, 5, 10) == 1 ? "true" : "false");
}
