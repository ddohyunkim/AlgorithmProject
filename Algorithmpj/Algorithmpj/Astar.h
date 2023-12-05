#pragma once
#ifndef ASTAR_H
#define ASTAR_H

struct Node9;
int** createGraph9(int n);
struct Node9* createNode9(int city, int f, int g, int h, struct Node9* parent);
int heuristic(int city, int dest);
void printPath9(struct Node9* current);
void astar(int** graph, int start, int dest, int n);
void aStar();

int main();
int keyControl();
#endif
