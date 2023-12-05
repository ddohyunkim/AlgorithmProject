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

// 계수 정렬 함수
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

    // 각 원소의 등장 횟수를 세기
    for (i = 0; i < size; i++) {
        count[a[i]]++;
    }

    // 정렬된 결과를 output 배열에 저장
    j = 0;
    int k = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            output[j++] = i;
            count[i]--;
        } printf("\n %d단계>>", i + 1);
        for (int k = 0; k < j; k++) {
            printf("%d ", output[k]);
        } printf("\n");
    }

    // 정렬된 결과를 원래 배열로 복사
    for (i = 0; i < size; i++) {
        a[i] = output[i];
    }

    free(count);
    free(output);
}


// 계수 정렬을 수행하는 함수
void myCounting() {
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
    for (i = 0; i < size; i++) printf("%d ", list[i]);
    printf("\n<<<<<<<<<< 계수 정렬 수행 >>>>>>>>>>\n");

    countingSort(list, size);

    // 정렬된 배열 출력
    printf("\n정렬된 원소 : ");
    for (i = 0; i < size; i++) printf("%d ", list[i]);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}
