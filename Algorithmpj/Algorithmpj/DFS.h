#pragma once
#ifndef DFS_H
#define DFS_H

// ���� �켱 Ž��
struct Node;
struct Graph;
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void dfs(struct Graph* graph, int vertex);
void DFS();


int main();
int keyControl();
#endif
