#pragma once
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

struct RBNode {
    int key;
    enum NodeColor color;
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
};

struct RBNode* RBcreateNode(int key);
void RBinsert(struct RBNode** root, int key);
void RBpreorderTraversal(struct RBNode* root);
void RBpostorderTraversal(struct RBNode* root);
void RBinorderTraversal(struct RBNode* root);
void fixInsert(struct RBNode* root, struct RBNode* node);
void leftRotate(struct RBNode* root, struct RBNode* x);
void rightRotate(struct RBNode* root, struct RBNode* y);
void myRedBlack();

// 선언 추가
void leftRotate(struct RBNode* root, struct RBNode* x);
void rightRotate(struct RBNode* root, struct RBNode* y);

int main();
int keyControl();
#endif // RED_BLACK_TREE_H