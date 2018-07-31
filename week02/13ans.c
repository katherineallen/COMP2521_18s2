#include <stdlib.h>

int main (int argc, char*argv[]){
	return EXIT_SUCCESS;
}

void swap(int*a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}