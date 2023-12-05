#pragma once
#ifndef R_TREE_H
#define R_TREE_H

#define R 2

struct RTreeNode {
    int n;               // 현재 노드의 키 개수
    int keys[2 * R - 1];  // 키 배열
    struct RTreeNode* children[2 * R];  // 자식 배열
    int leaf;            // 리프 노드 여부 (1: 리프, 0: 내부 노드)
};

struct RTree {
    struct RTreeNode* root;
};

struct RTreeNode* createRNode(int leaf);
struct RTree* initializeRTree();
void RsplitChild(struct RTreeNode* parent, int index);
void RinsertNonFull(struct RTreeNode* node, int key);
void Rinsert(struct RTree* tree, int key);
void printRTree(struct RTreeNode* root, int level);
void myR();

int main();
int keyControl();
#endif