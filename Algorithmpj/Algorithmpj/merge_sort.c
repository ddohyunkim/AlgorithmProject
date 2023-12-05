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

extern int size;

void mergeSort(int a[], int m, int n, int size) {
    int middle, i, j, k, t;
    int sorted[MAX];

    if (m < n) {
        middle = (m + n) / 2;
        mergeSort(a, m, middle, size);
        mergeSort(a, middle + 1, n, size);

        i = m;
        j = middle + 1;
        k = m;

        while (i <= middle && j <= n) {
            if (a[i] <= a[j]) {
                sorted[k++] = a[i++];
            }
            else {
                sorted[k++] = a[j++];
            }
        }

        if (i > middle) {
            for (t = j; t <= n; t++, k++) {
                sorted[k] = a[t];
            }
        }
        else {
            for (t = i; t <= middle; t++, k++) {
                sorted[k] = a[t];
            }
        }

        for (t = m; t <= n; t++) {
            a[t] = sorted[t];
        }

        printf("\n 병합 정렬 >> ");
        for (t = 0; t < size; t++) {
            printf("%4d ", a[t]);
        }
    }
}

void myMerge() {
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
    printf("\n<<<<<<<<<< 병합 정렬 수행 >>>>>>>>>>\n");

    mergeSort(list, 0, size - 1, size);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}