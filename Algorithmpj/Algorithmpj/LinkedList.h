#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node7;
struct Set;
struct Node7* createNode7(int data);
struct Set* createSet();
void Make_Set(struct Set* set, int data);
struct Node7* Find_Set(struct Set* set, int data);
void Union2(struct Set* set, int x, int y);
void displaySets(struct Set* set);
void myLinked();

int main();
int keyControl();
#endif
