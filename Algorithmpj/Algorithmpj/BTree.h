#pragma once
#ifndef B_TREE_H
#define B_TREE_H

#define M 2

struct BTreeNode {
    int n;
    int keys[2 * M - 1];
    struct BTreeNode* children[2 * M];
    int leaf;
};

struct BTree {
    struct BTreeNode* root;
};

struct BTreeNode* BcreateNode(int leaf);
struct BTree* initializeBTree();
void splitChild(struct BTreeNode* parent, int index);
void insertNonFull(struct BTreeNode* node, int key);
void Binsert(struct BTree* tree, int key);
void printBTree(struct BTreeNode* root, int level);
void myB();

int main();
int keyControl();
#endif