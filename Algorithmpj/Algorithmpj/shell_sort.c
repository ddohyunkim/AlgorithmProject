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

void shellSort(int a[], int size) {
    int i, interval;
    int j, item;

    interval = size / 2;

    while (interval >= 1) {
        for (i = 0; i < interval; i++) {
            for (j = i + interval; j < size; j = j + interval) {
                item = a[j];
                int k;
                for (k = j - interval; k >= i && item < a[k]; k = k - interval) {
                    a[k + interval] = a[k];
                }
                a[k + interval] = item;
            }
        }

        printf("\n interval=%d >> ", interval);
        for (i = 0; i < size; i++) printf("%d ", a[i]);
        printf("\n");

        interval = interval / 2;
    }
}

void myShell() {
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
    for (i = 0; i < size; i++) printf("%3d ", list[i]);
    printf("\n<<<<<<<<<< 쉘 정렬 수행 >>>>>>>>>>\n");

    shellSort(list, size);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}