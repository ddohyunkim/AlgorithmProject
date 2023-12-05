#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

#define SUBMIT 4

enum {
    BLACK, // 0
    DARK_BLUE, // 1
    DARK_GREEN, // 2
    DARK_SKYBLUE, // 3
    DARK_RED, // 4
    DARK_VOILET, // 5
    DARK_YELLOW, // 6
    GRAY, // 7
    DARK_GRAY, // 8
    BLUE, // 9
    GREEN, // 10
    SKYBLUE, // 11
    RED, // 12
    VIOLET, // 13
    YELLOW, // 14
    WHITE, // 15
};

// ��� ���� �Լ�
void countingSort(int a[], int size) {
    int max = a[0];
    int i, j;
    for (i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    int* count = (int*)malloc((max + 1) * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // �� ������ ���� Ƚ���� ����
    for (i = 0; i < size; i++) {
        count[a[i]]++;
    }

    // ���ĵ� ����� output �迭�� ����
    j = 0;
    int k = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            output[j++] = i;
            count[i]--;
        } printf("\n %d�ܰ�>>", i + 1);
        for (int k = 0; k < j; k++) {
            printf("%d ", output[k]);
        } printf("\n");
    }

    // ���ĵ� ����� ���� �迭�� ����
    for (i = 0; i < size; i++) {
        a[i] = output[i];
    }

    free(count);
    free(output);
}


// ��� ������ �����ϴ� �Լ�
void myCounting() {
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
    for (i = 0; i < size; i++) printf("%d ", list[i]);
    printf("\n<<<<<<<<<< ��� ���� ���� >>>>>>>>>>\n");

    countingSort(list, size);

    // ���ĵ� �迭 ���
    printf("\n���ĵ� ���� : ");
    for (i = 0; i < size; i++) printf("%d ", list[i]);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}
