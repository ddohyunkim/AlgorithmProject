#pragma once
#ifndef BRANCH_H
#define BRANCH_H

#include <limits.h>

#define N 5 // 도시의 수


int minCost = INT_MAX; // 최소 비용을 저장하는 변수
int finalPath[N]; // 최종 최소 비용 경로를 저장하는 배열
int visited[N];
int graph[N][N];
void printGraph();
void printPath(int path[N]);
int isSafe2(int v, int k, int path[N]);
void tsp2(int path[N], int k, int cost);
void myBranch();

int main();
int keyControl();
#endif
