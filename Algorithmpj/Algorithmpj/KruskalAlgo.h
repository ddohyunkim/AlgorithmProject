#pragma once
#ifndef KRUSKAL_ALGO_H
#define KRUSKAL_ALGO_H

#define MAX_VERTICES 100
#define MAX_EDGES 100
#include <stdbool.h>

// ������ ǥ���ϴ� ����ü
struct Edge {
    int start;   // ���� ����
    int end;     // �� ����
    int weight;  // ����ġ
};

// �׷����� ǥ���ϴ� ����ü
struct Graph {
    int V;                // ������ ����
    int E;                // ������ ����
    struct Edge edges[MAX_EDGES];  // ���� ������ ��� �迭
};

int findParent(int parent[], int i);
void unionSets(int parent[], int x, int y);
int compareEdges(const void* a, const void* b);
void kruskal(struct Graph* graph);
void myKruskal();

// ���� �˰����� ���� Graph ����ü
struct PGraph {
    int V;                 // ������ ����
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // ���� ���
};

int findMinKey(int key[], bool mstSet[], int V);
void prim(struct PGraph* graph);
void myPrim();

//�׸��� �˰���
// ȸ�Ǹ� ��Ÿ���� ����ü
struct Meeting {
    int start, end;
    int id;  // ȸ�� ��ȣ
};

int compareMeetings(const void* a, const void* b);
void printMaxMeetings(struct Meeting meetings[], int n);
void myGreed();

int main();
int keyControl();
#endif
