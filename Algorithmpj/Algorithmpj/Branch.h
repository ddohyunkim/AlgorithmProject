#pragma once
#ifndef BRANCH_H
#define BRANCH_H

#include <limits.h>

#define N 5 // ������ ��


int minCost = INT_MAX; // �ּ� ����� �����ϴ� ����
int finalPath[N]; // ���� �ּ� ��� ��θ� �����ϴ� �迭
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
