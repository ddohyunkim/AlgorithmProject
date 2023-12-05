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
    int step = 1;  // 단계를 나타내는 변수
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
        printf("\n\n %d 단계 : ", step);
        for (int i = 0; i < size; i++) {
            printf("%3d ", output[i]);
        }

        exp *= 10;  // 다음 단계로 이동
        step += 1;  // 단계를 1씩 늘림
    }
}

void myRadix() {
    int list[MAX];
    setColor(WHITE);

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("정렬할 원소를 입력하세요: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n정렬할 원소 : ");
    for (int i = 0; i < size; i++) printf("%3d ", list[i]);
    printf("\n<<<<<<<<<< 기수 정렬 수행 >>>>>>>>>>\n");

    radixSort(list);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}