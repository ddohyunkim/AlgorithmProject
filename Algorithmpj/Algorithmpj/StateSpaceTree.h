#pragma once
#ifndef STATESPACE_TREE_H
#define STATESPACE_TREE_H

#define N 5 // ������ ��

void tsp(int current, int visited, int graph[N][N], int path[N], int path_index, int* min_cost);
void StateSpaceTree();
void mySpace();

int main();
int keyControl();
#endif