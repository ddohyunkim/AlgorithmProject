#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

#define MAX 30
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


void pArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

int isCyclicUtil(int v, int** graph, int* visited, int* recStack, int size) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < size; i++) {
            if (graph[v][i]) {
                if (!visited[i] && isCyclicUtil(i, graph, visited, recStack, size)) {
                    return 1;
                }
                else if (recStack[i]) {
                    return 1;
                }
            }
        }
    }

    recStack[v] = 0;
    return 0;
}

int isCyclic(int** graph, int size) {
    int* visited = (int*)malloc(size * sizeof(int));
    int* recStack = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, graph, visited, recStack, size)) {
                free(visited);
                free(recStack);
                return 1;
            }
        }
    }

    free(visited);
    free(recStack);
    return 0;
}

void topologicalSort(int a[], int size) {
    // �׷����� ���� ������ ���� ��ķ� ǥ��
    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            graph[i][j] = 0;
        }
    }

    // �׷����� ���� ���� ����
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[i]) {
                graph[i][j] = 1;  // ������ �ٲپ�� �մϴ�.
            }
            else {
                graph[j][i] = 1;
            }
        }
    }

    // ����Ŭ �˻�
    if (isCyclic(graph, size)) {
        printf("�׷����� ����Ŭ�� �ֽ��ϴ�. ���� ������ ������ �� �����ϴ�.\n");

        // �޸� ����
        for (int i = 0; i < size; i++) {
            free(graph[i]);
        }
        free(graph);

        return; // �Լ� ����
    }

    int* inDegree = (int*)calloc(size, sizeof(int));
    int* result = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    int resultIndex = 0;

    for (int i = 0; i < size; i++) {
        int current = -1;

        for (int j = 0; j < size; j++) {
            if (inDegree[j] == 0) {
                for (int k = 0; k < size; k++) {
                    if (graph[j][k] == 1) {
                        inDegree[k]--;
                    }
                }

                current = j;
                break;
            }
        }

        if (current == -1) {
            break;
        }

        result[resultIndex++] = a[current];

        printf("���� ���� ����: ");
        pArray(result, resultIndex);
    }

    printf("���� ���� ���: ");
    pArray(result, size);

    free(inDegree);
    free(result);
    for (int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);
}

void myTopological() {
    int list[MAX];
    int i, size;
    setColor(WHITE);

    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("���� ������ ���Ҹ� �Է��ϼ���: ");
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n���� ������ ���� : ");
    pArray(list, size);
    printf("\n<<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");

    topologicalSort(list, size);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main �Լ� ȣ��
        }
    }
}