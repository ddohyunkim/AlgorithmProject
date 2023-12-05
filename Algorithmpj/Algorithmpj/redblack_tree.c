#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"

#define SUBMIT 4

enum NodeColor {
    NODE_RED,
    NODE_BLACK
};

enum {
    BLACK, //0
    DARK_BLUE, //1
    DARK_GREEN, //2
    DARK_SKYBLUE, //3
    DARK_RED, //4
    DARK_VOILET, //5
    DAKR_YELLOW, //6
    GRAY, //7
    DARK_GRAY, //8
    BLUE, //9
    GREEN, //10
    SKYBLUE, //11
    RED, //12
    VIOLET, //13
    YELLOW, //14
    WHITE, //15
};

struct RBNode* RBcreateNode(int key) {
    struct RBNode* newNode = (struct RBNode*)malloc(sizeof(struct RBNode));
    newNode->key = key;
    newNode->color = NODE_RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void RBinsert(struct RBNode** root, int key) {
    struct RBNode* newNode = RBcreateNode(key);
    struct RBNode* parent = NULL;
    struct RBNode* current = *root;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (parent == NULL) {
        *root = newNode;
    }
    else if (key < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    fixInsert(*root, newNode);
}


void fixInsert(struct RBNode* root, struct RBNode* node) {
    while (node->parent != NULL && node->parent->color == NODE_RED) {
        if (node->parent == node->parent->parent->left) {
            struct RBNode* uncle = node->parent->parent->right;

            if (uncle != NULL && uncle->color == NODE_RED) {
                node->parent->color = NODE_BLACK;
                uncle->color = NODE_BLACK;
                node->parent->parent->color = NODE_RED;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(root, node);
                }

                node->parent->color = NODE_BLACK;
                node->parent->parent->color = NODE_RED;
                rightRotate(root, node->parent->parent);
            }
        }
        else {
            struct RBNode* uncle = node->parent->parent->left;

            if (uncle != NULL && uncle->color == NODE_RED) {
                node->parent->color = NODE_BLACK;
                uncle->color = NODE_BLACK;
                node->parent->parent->color = NODE_RED;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(root, node);
                }

                node->parent->color = NODE_BLACK;
                node->parent->parent->color = NODE_RED;
                leftRotate(root, node->parent->parent);
            }
        }
    }

    root->color = NODE_BLACK;
}

void leftRotate(struct RBNode* root, struct RBNode* x) {
    struct RBNode* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(struct RBNode* root, struct RBNode* y) {
    struct RBNode* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        root = x;
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void RBpreorderTraversal(struct RBNode* root) {
    if (root != NULL) {
        printf("(%d, %s) ", root->key, root->color == NODE_RED ? "����" : "����");
        RBpreorderTraversal(root->left);
        RBpreorderTraversal(root->right);
    }
}


void RBinorderTraversal(struct RBNode* root) {
    if (root != NULL) {
        RBinorderTraversal(root->left);
        printf("(%d, %s) ", root->key, root->color == NODE_RED ? "����" : "����");
        RBinorderTraversal(root->right);
    }
}

void RBpostorderTraversal(struct RBNode* root) {
    if (root != NULL) {
        RBpostorderTraversal(root->left);
        RBpostorderTraversal(root->right);
        printf("(%d, %s) ", root->key, root->color == NODE_RED ? "����" : "����");
    }
}


void myRedBlack() {
    struct RBNode* root = NULL;
    int size, key;
    setColor(WHITE);

    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("���Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < size; ++i) {
        scanf_s("%d", &key);
        RBinsert(&root, key);
    }

    printf("���� ��ȸ ���: ");
    RBpreorderTraversal(root);
    printf("\n");

    printf("���� ��ȸ ���: ");
    RBinorderTraversal(root);
    printf("\n");

    printf("���� ��ȸ ���: ");
    RBpostorderTraversal(root);
    printf("\n");


    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main �Լ� ȣ��
        }
    }
}