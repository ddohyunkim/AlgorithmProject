#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "KruskalAlgo.h"

// 정점의 개수와 간선의 개수를 상수로 정의
#define MAX_VERTICES 100
#define MAX_EDGES 100
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

int findMinKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

// 프림 알고리즘 구현
void prim(struct PGraph* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < graph->V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->V - 1; count++) {
        int u = findMinKey(key, mstSet, graph->V);

        mstSet[u] = true;

        for (int v = 0; v < graph->V; v++) {
            if (graph->adjMatrix[u][v] && !mstSet[v] && graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    printf("최소 신장 트리 (프림 알고리즘 결과):\n");
    for (int i = 1; i < graph->V; i++)
        printf("%d - %d : %d\n", parent[i], i, key[i]);
}

void myPrim() {
    struct PGraph graph;
    int V;

    setColor(WHITE);

    printf("정점의 개수를 입력하세요: ");
    scanf_s("%d", &V);
    graph.V = V;

    printf("인접 행렬 정보를 입력하세요:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf_s("%d", &graph.adjMatrix[i][j]);
        }
    }

    prim(&graph);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}