#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

struct Node6;
struct Graph6;
struct Node6* createNode6(int v, int weight);
struct Graph6* createGraph6(int vertices);
void addEdge6(struct Graph6* graph, int src, int dest, int weight);
void printDijkstra(int dist[], int n);
int minDistance(int dist[], int sptSet[], int n);
void dijkstra(struct Graph6* graph, int src);
void Dijkstra();

int main();
int keyControl();
#endif
