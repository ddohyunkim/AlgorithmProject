#include<stdio.h>
#include "algo.h"

// ���� ����
void SelectionSort(int a[], int size); // selection_sort.c���� ������ �Լ� ����
//���� ����
void bubbleSort(int a[], int size);

int main_manu(void) {
    int list1[50], list2[50];
    int i, size;

    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("������ ���Ҹ� �Է��ϼ���: ");
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list1[i]);
        list2[i] = list1[i];
    }

    printf("\n������ ���� : ");
    for (i = 0; i < size; i++) printf("%3d ", list1[i]);

    SelectionSort(list1, size);
    
    printf("\n���� ������ ���� : ");
    for (i = 0; i < size; i++) printf("%3d ", list2[i]);
    printf("\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");
    bubbleSort(list2, size);

    getchar();
    return 0;
}