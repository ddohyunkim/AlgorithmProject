#include <stdio.h>
#include <stdlib.h>
#include "KruskalAlgo.h"

// ������ ������ ������ ������ ����� ����
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

// �θ� ã�� �Լ� (Union-Find �˰���)
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// �� �κ������� ��ġ�� �Լ� (Union-Find �˰���)
void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

// ������ ����ġ ������ �����ϴ� �Լ� (��������)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// ũ�罺Į �˰��� ����
void kruskal(struct Graph* graph) {
    int parent[MAX_VERTICES];  // �� ������ �θ� �����ϴ� �迭, -1�� �ʱ�ȭ
    for (int i = 0; i < graph->V; ++i)
        parent[i] = -1;

    // ������ ����ġ ������ ����
    qsort(graph->edges, graph->E, sizeof(struct Edge), compareEdges);

    // �ּ� ���� Ʈ���� �����ϱ� ���� ������ ����
    for (int i = 0; i < graph->E; ++i) {
        int x = findParent(parent, graph->edges[i].start);
        int y = findParent(parent, graph->edges[i].end);

        // ����Ŭ�� �������� �ʴ� ��쿡�� �ش� ������ ����
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

    printf("������ ������ �Է��ϼ���: ");
    scanf_s("%d", &V);
    graph.V = V;

    printf("������ ������ �Է��ϼ���: ");
    scanf_s("%d", &E);
    graph.E = E;

    printf("���� ������ �Է��ϼ��� (���� ���� �� ���� ����ġ):\n");
    for (int i = 0; i < E; ++i) {
        scanf_s("%d %d %d", &graph.edges[i].start, &graph.edges[i].end, &graph.edges[i].weight);
    }

    printf("\n�ּ� ���� Ʈ�� (ũ�罺Į �˰��� ���):\n");
    kruskal(&graph);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main �Լ� ȣ��
        }
    }
}
