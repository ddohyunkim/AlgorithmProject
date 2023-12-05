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

void insertionSort(int a[], int size) {
    int i, j, t, temp;

    for (i = 1; i < size; i++) {
        temp = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > temp)) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = temp;
        printf("\n %d�ܰ� : ", i);
        for (t = 0; t < size; t++) printf("%3d ", a[t]);
    }
}

void myInsert() {
    int list[50];
    int i, size;
    setColor(WHITE);
    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("������ ���Ҹ� �Է��ϼ���: ");
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n������ ���� : ");
    for (i = 0; i < size; i++) printf("%3d ", list[i]);
    printf("\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");

    insertionSort(list, size);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}