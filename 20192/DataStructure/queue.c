
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "queueADT.h"


int main() {
	printf("입력받은 숫자들의 각자리수를 큐에 넣고 max,min값만 선택하는 프로그램\n\n");
	int arrNum[10];		// 입력받은 수의 배열
	int digit[4];		// 각 자리수
	int temp[10];
	int result;
	int cnt = 0, min,max;
	int min_value=0, max_value=0;
	QUEUE* arrQueue[10];// 큐 배열
	
	while (1) {
		printf("4자리 숫자를 입력(최대10번반복가능,0입력시 종료)#%d : ",cnt);
		scanf_s("%d", arrNum+cnt);
		while (1) {
			if (arrNum[cnt]>0&&(arrNum[cnt] < 1000 || arrNum[cnt]>9999)) {
				printf("[입력오류]4자리 숫자를 다시 입력하세요! : ");
				scanf_s("%d", arrNum + cnt);
			}else
				break;
		}
		if (arrNum[cnt] == 0)
			break;
		cnt++;
		if (cnt >= 10)
			break;
	}
	
	// 입력갯수만큼 큐를 만들고 각 큐에 해당 숫자를 한자리씩 enqueue
	for (int i = 0; i < cnt; i++) {
		arrQueue[i] = createQueue();
		digit[0] = arrNum[i] / 1000;
		digit[1] = (arrNum[i] % 1000) / 100;
		digit[2] = (arrNum[i] % 100) / 10;
		digit[3] = arrNum[i] % 10;
		for (int j = 0; j < 4; j++) {
			enqueue(arrQueue[i], digit[j]);
		}
	}

		
	for (int n = 3; n >= 0; n--) {
		// 각 큐에서 하나씩 dequeue한 값을 temp배열에 담는다.
		for (int i = 0; i < cnt; i++) {
			dequeue(arrQueue[i], temp + i);
		}

		// temp배열에서 최대,최소값을 찾는다
		max = 0;
		min = 10;
		for (int i = 0; i < cnt; i++) {
			if (temp[i] >= max) {
				max = temp[i];
			}
			if (temp[i] < min) {
				min = temp[i];
			}
		}
		max_value += max*pow(10, n);
		min_value += min*pow(10, n);
	}

	printf("각자릿수의 최댓값 : %d\n", max_value);
	printf("각자릿수의 최솟값 : %d\n", min_value);

	// 메모리할당 해제
	for (int i = 0; i < cnt; i++) {
		destoryQueue(arrQueue[i]);
	}
}

