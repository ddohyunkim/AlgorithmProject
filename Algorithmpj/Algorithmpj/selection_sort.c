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

void SelectionSort(int a[], int size) {
	int i, j, t, min, temp;

	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		printf("\n%d�ܰ� : ", i + 1);
		for (t = 0; t < size; t++) {
			printf("%3d ", a[t]);
		}
	}
}
void mySelect() {
	int list[50];
    int i, size;

    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("������ ���Ҹ� �Է��ϼ���: ");
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n������ ���� : ");
    for (i = 0; i < size; i++) printf("%3d ", list[i]);
	printf("\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");

    SelectionSort(list, size);

    getchar();
	while (1) {
		if (keyControl() == SUBMIT) {
			main();
		}
	}
}