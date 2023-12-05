#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Bellman.h"

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

// ���� ���� �˰���
struct Edge7 {
    int src, dest, weight;
};

struct Graph7 {
    int numVertices, numEdges;
    struct Edge7* edge;
};

struct Graph7* createGraph7(int vertices, int edges) {
    struct Graph7* graph = (struct Graph7*)malloc(sizeof(struct Graph7));
    graph->numVertices = vertices;
    graph->numEdges = edges;
    graph->edge = (struct Edge7*)malloc(edges * sizeof(struct Edge7));
    return graph;
}

void printShortestPath(int dist[], int n) {
    printf("���   �ִ� �Ÿ�\n");
    for (int i = 0; i < n; ++i) {
        printf("%d     %d\n", i, dist[i]);
    }
}

void bellmanFord(struct Graph7* graph, int src) {
    int V = graph->numVertices;
    int E = graph->numEdges;
    int dist[20];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("���� ����Ŭ�� �����մϴ�.\n");
            return;
        }
    }

    printShortestPath(dist, V);
}

void BellmanFord() {
    setColor(WHITE);
    int close = 1;
    int vertices, edges, i;
    printf("����� ���� �Է��ϼ���: ");
    scanf_s("%d", &vertices);

    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &edges);

    struct Graph7* graph = createGraph7(vertices, edges);

    for (i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("���� %d (����� ������ ����ġ): ", i + 1);
        scanf_s("%d %d %d", &src, &dest, &weight);
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }

    int startVertex;
    printf("����-���� �˰����� ������ ���� ��带 �Է��ϼ���: ");
    scanf_s("%d", &startVertex);

    printf("%d�� ��忡�� �����Ͽ� ��� �������� �ִ� ���:\n", startVertex);
    bellmanFord(graph, startVertex);

    free(graph->edge);
    free(graph);

    int keyPressed;
    while (1) {
        keyPressed = keyControl();
        if (keyPressed == SUBMIT) {
            break;
        }
    }

    if (keyPressed == SUBMIT) {
        main();  // main �Լ� ȣ��
    }
}
