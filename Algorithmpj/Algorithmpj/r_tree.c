#include <stdio.h>
#include <stdlib.h>
#include "RTree.h"

#define R 2
#define SUBMIT 4

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

struct RTreeNode* createRNode(int leaf) {
    struct RTreeNode* newNode = (struct RTreeNode*)malloc(sizeof(struct RTreeNode));
    newNode->n = 0;
    newNode->leaf = leaf;
    for (int i = 0; i < 2 * R; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

struct RTree* initializeRTree() {
    struct RTree* tree = (struct RTree*)malloc(sizeof(struct RTree));
    tree->root = createRNode(1);  // 리프 노드로 초기화
    return tree;
}

void RsplitChild(struct RTreeNode* parent, int index) {
    struct RTreeNode* newChild = createRNode(parent->children[index]->leaf);
    struct RTreeNode* child = parent->children[index];

    newChild->n = R - 1;
    for (int i = 0; i < R - 1; ++i) {
        newChild->keys[i] = child->keys[i + R];
    }

    if (!child->leaf) {
        for (int i = 0; i < R; ++i) {
            newChild->children[i] = child->children[i + R];
            child->children[i + R] = NULL;
        }
    }

    child->n = R - 1;

    for (int i = parent->n; i > index; --i) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }
    parent->keys[index] = child->keys[R - 1];
    parent->children[index + 1] = newChild;

    parent->n++;
}

void RinsertNonFull(struct RTreeNode* node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    }
    else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }

        i++;

        if (node->children[i]->n == 2 * R - 1) {
            RsplitChild(node, i);

            if (key > node->keys[i]) {
                i++;
            }
        }

        RinsertNonFull(node->children[i], key);
    }
}

void Rinsert(struct RTree* tree, int key) {
    struct RTreeNode* root = tree->root;

    if (root->n == 2 * R - 1) {
        struct RTreeNode* newRoot = createRNode(0);
        tree->root = newRoot;
        newRoot->children[0] = root;
        RsplitChild(newRoot, 0);
        RinsertNonFull(newRoot, key);
    }
    else {
        RinsertNonFull(root, key);
    }
}

void printRTree(struct RTreeNode* root, int level) {
    if (root != NULL) {
        if (root->leaf) {
            // 리프 노드인 경우
            for (int i = 0; i < root->n; i++) {
                for (int j = 0; j < level; j++) {
                    printf("   ");
                }
                printf("%d\n", root->keys[i]);
            }
        }
        else {
            // 내부 노드인 경우
            int i;
            for (i = 0; i < root->n; i++) {
                printRTree(root->children[i], level + 1);
                for (int j = 0; j < level; j++) {
                    printf("   ");
                }
                printf("%d\n", root->keys[i]);
            }
            printRTree(root->children[i], level + 1);
        }
    }
}


void myR() {
    struct RTree* rTree = initializeRTree();

    int R_SIZE, size, key;
    setColor(WHITE);

    printf("R-트리 리프 노드 키 개수(R)를 입력하세요: ");
    scanf_s("%d", &R_SIZE);

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("원소를 입력하세요: ");
    for (int i = 0; i < size; ++i) {
        scanf_s("%d", &key);
        Rinsert(rTree, key);
    }

    printf("\n최종 R-트리 상태:\n");
    printRTree(rTree->root, 0);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}