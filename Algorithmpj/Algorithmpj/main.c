#include<stdio.h>
#include "algo.h"

// 선택 정렬
void SelectionSort(int a[], int size); // selection_sort.c에서 정의한 함수 선언
//버블 정렬
void bubbleSort(int a[], int size);

int main_manu(void) {
    int list1[50], list2[50];
    int i, size;

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("정렬할 원소를 입력하세요: ");
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list1[i]);
        list2[i] = list1[i];
    }

    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) printf("%3d ", list1[i]);

    SelectionSort(list1, size);
    
    printf("\n버블 정렬할 원소 : ");
    for (i = 0; i < size; i++) printf("%3d ", list2[i]);
    printf("\n<<<<<<<<<< 버블 정렬 수행 >>>>>>>>>>\n");
    bubbleSort(list2, size);

    getchar();
    return 0;
}