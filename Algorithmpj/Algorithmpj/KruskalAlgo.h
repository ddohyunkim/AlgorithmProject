#pragma once
#ifndef KRUSKAL_ALGO_H
#define KRUSKAL_ALGO_H

#define MAX_VERTICES 100
#define MAX_EDGES 100
#include <stdbool.h>

// 간선을 표현하는 구조체
struct Edge {
    int start;   // 시작 정점
    int end;     // 끝 정점
    int weight;  // 가중치
};

// 그래프를 표현하는 구조체
struct Graph {
    int V;                // 정점의 개수
    int E;                // 간선의 개수
    struct Edge edges[MAX_EDGES];  // 간선 정보를 담는 배열
};

int findParent(int parent[], int i);
void unionSets(int parent[], int x, int y);
int compareEdges(const void* a, const void* b);
void kruskal(struct Graph* graph);
void myKruskal();

// 프림 알고리즘을 위한 Graph 구조체
struct PGraph {
    int V;                 // 정점의 개수
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 인접 행렬
};

int findMinKey(int key[], bool mstSet[], int V);
void prim(struct PGraph* graph);
void myPrim();

//그리디 알고리즘
// 회의를 나타내는 구조체
struct Meeting {
    int start, end;
    int id;  // 회의 번호
};

int compareMeetings(const void* a, const void* b);
void printMaxMeetings(struct Meeting meetings[], int n);
void myGreed();

int main();
int keyControl();
#endif
