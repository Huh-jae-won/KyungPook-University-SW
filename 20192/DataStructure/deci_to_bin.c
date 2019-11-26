// stack을 구현하여 헤더파일로 만들고 
// stack을 사용할만한 예제를 만듦
#include <stdio.h>
#include <stdbool.h>
#include "stacksADT.h"
#pragma warning(disable:4996)	// scanf_s말고 scanf를 사용하기 위해

int main(void) {
	// 10진수를 2진수로 바꾸는 프로그램 구현
	unsigned int num;
	int* digit;
	STACK* stack2;

	stack2 = createStack();

	printf("Enter an integer: ");
	scanf("%d", &num);
	while (num>0) {
		digit = (int*)malloc(sizeof(int));
		*digit = num % 2;
		pushStack(stack2, digit);		// num을 2진수로 나누고 난 나머지를 스택에 저장
		num = num / 2;
	}
	printf("bin_num is : ");
	while (!emptyStack(stack2)) {			// 스택에서 하나씩 꺼내며 출력
		digit = (int*)popStack(stack2);
		printf("%1d", *digit);
	}
	printf("\n");

	destroyStack(stack2);
	return 0;
}
