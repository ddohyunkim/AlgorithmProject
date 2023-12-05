#include <stdio.h>
#include "algo.h"

#define SUBMIT 4

enum {
	BLACK, //0
	DARK_BLUE, //1
	DARK_GREEN, //2
	DARK_SKYBLUE, //3
	DARK_RED, //4
	DARK_VOILET, //5
	DAKR_YELLOW, //6
	GRAY, //7
	DARK_GRAY, //8
	BLUE, //9
	GREEN, //10
	SKYBLUE, //11
	RED, //12
	VIOLET, //13
	YELLOW, //14
	WHITE, //15
};

int i = 0;

void quickSort(int a[], int begin, int end, int size) {
	int p;
	if (begin < end) {
		int L = begin;
		int R = end;
		int pivot = (begin + end) / 2;
		printf("\n [%d단계 : pivot = %d ] \n", ++i, a[pivot]);

		while (L < R) {
			while ((a[L] < a[pivot]) && (L < R)) L++;
			while ((a[R] >= a[pivot]) && (L < R)) R--;

			if (L < R) {
				int temp = a[L];
				a[L] = a[R];
				a[R] = temp;
				if (L == pivot) pivot = R;
			}
		}

		int temp = a[pivot];
		a[pivot] = a[R];
		a[R] = temp;

		for (int t = 0; t < size; t++) printf("%4d", a[t]);
		printf("\n");

		quickSort(a, begin, R - 1, size);
		quickSort(a, R + 1, end, size);
	}
}
void myQuick() {
	int list[50];
	int i, size;
	setColor(WHITE);
	printf("원소 개수를 입력하세요: ");
	scanf_s("%d", &size);

	printf("정렬할 원소를 입력하세요: ");
	for (i = 0; i < size; i++) {
		scanf_s("%d", &list[i]);
	}

	printf("\n정렬할 원소 : ");
	for (i = 0; i < size; i++) printf("%3d", list[i]);
	printf("\n\n<<<<<<<<<< 퀵 정렬 수행 >>>>>>>>>>\n");
	
	quickSort(list, 0, size - 1, size);

	getchar();
	while (1) {
		if (keyControl() == SUBMIT) {
			main();
		}
	}
}