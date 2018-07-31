#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char*argv[]) {
	return EXIT_SUCCESS;
}

int isSorted(int *a, int n) {
	int i = 0;
	int isSorted = TRUE;

	while (i < n-2) {
		if (a[i] > a[i+1]) {
			isSorted = FALSE;
		}
		i++;
	}

	return isSorted;
}


int isSortedFor(int *a, int n) {
	int isSorted = TRUE;
	int i;

	for (i=0; i < n-2; i++) {
		if (a[i] > a[i+1]) {
			isSorted = FALSE;
		}
	}

	return isSorted;
}


int isSortedBreak(int *a, int n) {
	int isSorted;
	int i;

	for (i = 0; i < n-2; i++) {
		if (a[i] > a[i+1]) {
			break;
		}
	}

	if (i == n-2){
		isSorted = TRUE;
	} else {
		isSorted = FALSE;
	}

	return isSorted;
}

int isSortedMultipleReturn(int *a, int n) {
	int isSorted;
	int i;

	for (i = 0; i < n-2; i++) {
		if (a[i] > a[i+1]) {
			break;
		}
	}

	if (i == n-2){
		return TRUE;
	} else {
		return FALSE;
	}

	return isSorted;
}


int isSortedInlineReturn(int *a, int n) {
	int i;

	for (i = 0; i < n-2; i++) {
		if (a[i] > a[i+1]) {
			return FALSE;
		}
	}

	return TRUE;
}









