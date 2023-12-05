#pragma once
#ifndef TREESET_H
#define TREESET_H

struct Node8;
struct Node8* make_set(int x);
struct Node8* find_set(struct Node8* node);
void union_sets(struct Node8* x, struct Node8* y);
void print_sets(struct Node8* nodes[], int n);
void free_memory(struct Node8* nodes[], int n);
void myTree();

int main();
int keyControl();
#endif
