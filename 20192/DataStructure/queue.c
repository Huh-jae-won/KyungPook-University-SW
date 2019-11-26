
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "queueADT.h"


int main() {
	printf("�Է¹��� ���ڵ��� ���ڸ����� ť�� �ְ� max,min���� �����ϴ� ���α׷�\n\n");
	int arrNum[10];		// �Է¹��� ���� �迭
	int digit[4];		// �� �ڸ���
	int temp[10];
	int result;
	int cnt = 0, min,max;
	int min_value=0, max_value=0;
	QUEUE* arrQueue[10];// ť �迭
	
	while (1) {
		printf("4�ڸ� ���ڸ� �Է�(�ִ�10���ݺ�����,0�Է½� ����)#%d : ",cnt);
		scanf_s("%d", arrNum+cnt);
		while (1) {
			if (arrNum[cnt]>0&&(arrNum[cnt] < 1000 || arrNum[cnt]>9999)) {
				printf("[�Է¿���]4�ڸ� ���ڸ� �ٽ� �Է��ϼ���! : ");
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
	
	// �Է°�����ŭ ť�� ����� �� ť�� �ش� ���ڸ� ���ڸ��� enqueue
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
		// �� ť���� �ϳ��� dequeue�� ���� temp�迭�� ��´�.
		for (int i = 0; i < cnt; i++) {
			dequeue(arrQueue[i], temp + i);
		}

		// temp�迭���� �ִ�,�ּҰ��� ã�´�
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

	printf("���ڸ����� �ִ� : %d\n", max_value);
	printf("���ڸ����� �ּڰ� : %d\n", min_value);

	// �޸��Ҵ� ����
	for (int i = 0; i < cnt; i++) {
		destoryQueue(arrQueue[i]);
	}
}

