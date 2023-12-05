#include <stdio.h>
#include "algo.h"

#define SUBMIT 4
#define MAX 30
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


int size = 0;

void radixSort(int a[]) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    int exp = 1;
    int step = 1;  // �ܰ踦 ��Ÿ���� ����
    while (max / exp > 0) {
        int output[MAX];
        int count[10] = { 0 };

        for (int i = 0; i < size; i++) {
            count[(a[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        // Print the sorted array
        printf("\n\n %d �ܰ� : ", step);
        for (int i = 0; i < size; i++) {
            printf("%3d ", output[i]);
        }

        exp *= 10;  // ���� �ܰ�� �̵�
        step += 1;  // �ܰ踦 1�� �ø�
    }
}

void myRadix() {
    int list[MAX];
    setColor(WHITE);

    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("������ ���Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n������ ���� : ");
    for (int i = 0; i < size; i++) printf("%3d ", list[i]);
    printf("\n<<<<<<<<<< ��� ���� ���� >>>>>>>>>>\n");

    radixSort(list);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}