#pragma once
#ifndef BELLMAN_H
#define BELLMAN_H

#define MAX_V 10

int V, E;
int adj[MAX_V][MAX_V];
void initAdj();
void floyd();
void myFloyd();


int main();
int keyControl();
#endif
