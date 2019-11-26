#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"
#pragma warning(disable:4996)

int main(void) {
	unsigned int num;
	int* digit;
	STACK* stack2;

	stack2 = createStack();

	printf("Enter an integer: ");
	scanf("%d", &num);
	while (num>0) {
		digit = (int*)malloc(sizeof(int));
		*digit = num % 2;
		pushStack(stack2, digit);
		num = num / 2;
	}
	printf("bin_num is : ");
	while (!emptyStack(stack2)) {
		digit = (int*)popStack(stack2);
		printf("%1d", *digit);
	}
	printf("\n");

	destroyStack(stack2);
	return 0;
}