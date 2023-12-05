#pragma once
#ifndef BELLMAN_H
#define BELLMAN_H

struct Edge7;
struct Graph7;
struct Graph7* createGraph7(int vertices, int edges);
void printShortestPath(int dist[], int n);
void bellmanFord(struct Graph7* graph, int src);
void BellmanFord();

int main();
int keyControl();
#endif
