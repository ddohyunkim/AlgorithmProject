#pragma once
#ifndef R_TREE_H
#define R_TREE_H

#define R 2

struct RTreeNode {
    int n;               // ���� ����� Ű ����
    int keys[2 * R - 1];  // Ű �迭
    struct RTreeNode* children[2 * R];  // �ڽ� �迭
    int leaf;            // ���� ��� ���� (1: ����, 0: ���� ���)
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