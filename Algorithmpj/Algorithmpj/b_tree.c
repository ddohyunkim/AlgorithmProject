#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

#define M 2
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


struct BTreeNode* BcreateNode(int leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->n = 0;
    newNode->leaf = leaf;
    for (int i = 0; i < 2 * M; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

struct BTree* initializeBTree() {
    struct BTree* tree = (struct BTree*)malloc(sizeof(struct BTree));
    tree->root = BcreateNode(1);
    return tree;
}

void splitChild(struct BTreeNode* parent, int index) {
    struct BTreeNode* newChild = BcreateNode(parent->children[index]->leaf);
    struct BTreeNode* child = parent->children[index];

    newChild->n = M - 1;
    for (int i = 0; i < M - 1; ++i) {
        newChild->keys[i] = child->keys[i + M];
    }

    if (!child->leaf) {
        for (int i = 0; i < M; ++i) {
            newChild->children[i] = child->children[i + M];
            child->children[i + M] = NULL;
        }
    }

    child->n = M - 1;

    for (int i = parent->n; i > index; --i) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }
    parent->keys[index] = child->keys[M - 1];
    parent->children[index + 1] = newChild;

    parent->n++;
}

void insertNonFull(struct BTreeNode* node, int key) {
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

        if (node->children[i]->n == 2 * M - 1) {
            splitChild(node, i);

            if (key > node->keys[i]) {
                i++;
            }
        }

        insertNonFull(node->children[i], key);
    }
}

void Binsert(struct BTree* tree, int key) {
    struct BTreeNode* root = tree->root;

    if (root->n == 2 * M - 1) {
        struct BTreeNode* newRoot = BcreateNode(0);
        tree->root = newRoot;
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
    }
    else {
        insertNonFull(root, key);
    }
}

void printBTree(struct BTreeNode* root, int level) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            printBTree(root->children[i], level + 1);
            for (int j = 0; j < level; j++) {
                printf("   ");
            }
            printf("%d\n", root->keys[i]);
        }
        printBTree(root->children[i], level + 1);
    }
}

void myB() {
    struct BTree* bTree = initializeBTree();

    int M_val, size, key;
    setColor(WHITE);

    printf("B-트리 차수(M)를 입력하세요: ");
    scanf_s("%d", &M_val);

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("원소를 입력하세요: ");
    for (int i = 0; i < size; ++i) {
        scanf_s("%d", &key);
        Binsert(bTree, key);
    }
    printf("\n최종 B-트리 상태:\n");
    printBTree(bTree->root, 0);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}
