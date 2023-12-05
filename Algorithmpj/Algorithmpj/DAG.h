#pragma once
#ifndef DAG_H
#define DAG_H

#define MAX_V 10

int V, E;
int adj[MAX_V][MAX_V];
void initAdj2();
void dijkstra2(int start);
void DAG();

int main();
int keyControl();
#endif
