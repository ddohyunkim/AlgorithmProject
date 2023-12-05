#pragma once
#ifndef BFS_H
#define BFS_H

struct Node3 {
    int vertex;
    struct Node3* next;
};

struct Graph3 {
    int numVertices;
    struct Node3** adjLists;
    int* visited;
};

struct Graph3* createGraph3(int vertices);
void addEdge3(struct Graph3* graph, int src, int dest);
void bfs(struct Graph3* graph, int startVertex);
void BFS();
void myBFS();

int main();
int keyControl();
#endif
