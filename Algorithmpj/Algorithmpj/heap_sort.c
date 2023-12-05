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

void printArray(int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[]) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);

        printf("\n\n %d 단계 : ", size - i);
        printArray(arr);
    }
}

void myHeap() {
    int list[MAX];
    setColor(WHITE);

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("정렬할 원소를 입력하세요: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n정렬할 원소 : ");
    printArray(list);
    printf("<<<<<<<<<< 히프 정렬 수행 >>>>>>>>>>\n");

    heapSort(list);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}
