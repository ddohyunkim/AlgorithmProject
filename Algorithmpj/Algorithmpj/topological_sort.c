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
    // 그래프의 간선 정보를 인접 행렬로 표현
    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            graph[i][j] = 0;
        }
    }

    // 그래프의 간선 정보 설정
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[i]) {
                graph[i][j] = 1;  // 방향을 바꾸어야 합니다.
            }
            else {
                graph[j][i] = 1;
            }
        }
    }

    // 사이클 검사
    if (isCyclic(graph, size)) {
        printf("그래프에 사이클이 있습니다. 위상 정렬을 수행할 수 없습니다.\n");

        // 메모리 해제
        for (int i = 0; i < size; i++) {
            free(graph[i]);
        }
        free(graph);

        return; // 함수 종료
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

        printf("위상 정렬 순서: ");
        pArray(result, resultIndex);
    }

    printf("위상 정렬 결과: ");
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

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("위상 정렬할 원소를 입력하세요: ");
    for (i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n위상 정렬할 원소 : ");
    pArray(list, size);
    printf("\n<<<<<<<<<< 위상 정렬 수행 >>>>>>>>>>\n");

    topologicalSort(list, size);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}