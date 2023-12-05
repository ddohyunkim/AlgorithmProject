#include <stdio.h>
#include <stdlib.h>
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

// 부모를 찾는 함수 (Union-Find 알고리즘)
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// 두 부분집합을 합치는 함수 (Union-Find 알고리즘)
void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

// 간선을 가중치 순으로 정렬하는 함수 (오름차순)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// 크루스칼 알고리즘 구현
void kruskal(struct Graph* graph) {
    int parent[MAX_VERTICES];  // 각 정점의 부모를 저장하는 배열, -1로 초기화
    for (int i = 0; i < graph->V; ++i)
        parent[i] = -1;

    // 간선을 가중치 순으로 정렬
    qsort(graph->edges, graph->E, sizeof(struct Edge), compareEdges);

    // 최소 신장 트리를 구성하기 위한 간선을 선택
    for (int i = 0; i < graph->E; ++i) {
        int x = findParent(parent, graph->edges[i].start);
        int y = findParent(parent, graph->edges[i].end);

        // 사이클을 형성하지 않는 경우에만 해당 간선을 선택
        if (x != y) {
            printf("%d - %d : %d\n", graph->edges[i].start, graph->edges[i].end, graph->edges[i].weight);
            unionSets(parent, x, y);
        }
    }
}

void myKruskal() {
    struct Graph graph;
    int V, E;
    setColor(WHITE);

    printf("정점의 개수를 입력하세요: ");
    scanf_s("%d", &V);
    graph.V = V;

    printf("간선의 개수를 입력하세요: ");
    scanf_s("%d", &E);
    graph.E = E;

    printf("간선 정보를 입력하세요 (시작 정점 끝 정점 가중치):\n");
    for (int i = 0; i < E; ++i) {
        scanf_s("%d %d %d", &graph.edges[i].start, &graph.edges[i].end, &graph.edges[i].weight);
    }

    printf("\n최소 신장 트리 (크루스칼 알고리즘 결과):\n");
    kruskal(&graph);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}
