#pragma once
#ifndef K_D_TREE_H
#define K_D_TREE_H

#define K 2

struct KDTreeNode {
    int point[K];
    struct KDTreeNode* left, * right;
};

struct KDTree {
    struct KDTreeNode* root;
};

struct KDTreeNode* createKDNode(int point[]);
struct KDTree* initializeKDTree();
struct KDTree* initializeKDTree();
void KDinsert(struct KDTree* tree, int point[]);
void printKDTree(struct KDTreeNode* root, int depth);
void KDpreorderTraversal(struct KDTreeNode* root, int depth);
void KDinorderTraversal(struct KDTreeNode* root, int depth);
void KDpostorderTraversal(struct KDTreeNode* root, int depth);
void myKD();

int main();
int keyControl();

#endif