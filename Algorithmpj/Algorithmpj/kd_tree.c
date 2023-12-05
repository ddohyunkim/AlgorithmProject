#include <stdio.h>
#include <stdlib.h>
#include "KDTree.h"

#define K 2
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

struct KDTreeNode* createKDNode(int point[]) {
    struct KDTreeNode* newNode = (struct KDTreeNode*)malloc(sizeof(struct KDTreeNode));
    for (int i = 0; i < K; ++i) {
        newNode->point[i] = point[i];
    }
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct KDTree* initializeKDTree() {
    struct KDTree* tree = (struct KDTree*)malloc(sizeof(struct KDTree));
    tree->root = NULL;
    return tree;
}

struct KDTreeNode* insertRecursive(struct KDTreeNode* root, int point[], int depth) {
    if (root == NULL) {
        return createKDNode(point);
    }

    int currentAxis = depth % K;

    if (point[currentAxis] < root->point[currentAxis]) {
        root->left = insertRecursive(root->left, point, depth + 1);
    }
    else {
        root->right = insertRecursive(root->right, point, depth + 1);
    }

    return root;
}

void KDinsert(struct KDTree* tree, int point[]) {
    tree->root = insertRecursive(tree->root, point, 0);
}

void printKDTree(struct KDTreeNode* root, int depth) {
    if (root != NULL) {
        printKDTree(root->left, depth + 1);

        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("(");
        for (int i = 0; i < K; i++) {
            printf("%d", root->point[i]);
            if (i < K - 1) {
                printf(", ");
            }
        }
        printf(")\n");

        printKDTree(root->right, depth + 1);
    }
}

void KDpreorderTraversal(struct KDTreeNode* root, int depth) {
    if (root != NULL) {
        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("(");
        for (int i = 0; i < K; i++) {
            printf("%d", root->point[i]);
            if (i < K - 1) {
                printf(", ");
            }
        }
        printf(")\n");

        KDpreorderTraversal(root->left, depth + 1);
        KDpreorderTraversal(root->right, depth + 1);
    }
}

void KDinorderTraversal(struct KDTreeNode* root, int depth) {
    if (root != NULL) {
        KDinorderTraversal(root->left, depth + 1);

        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("(");
        for (int i = 0; i < K; i++) {
            printf("%d", root->point[i]);
            if (i < K - 1) {
                printf(", ");
            }
        }
        printf(")\n");

        KDinorderTraversal(root->right, depth + 1);
    }
}

void KDpostorderTraversal(struct KDTreeNode* root, int depth) {
    if (root != NULL) {
        KDpostorderTraversal(root->left, depth + 1);
        KDpostorderTraversal(root->right, depth + 1);

        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("(");
        for (int i = 0; i < K; i++) {
            printf("%d", root->point[i]);
            if (i < K - 1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
}

// myKD 함수 내에서 순회를 호출하도록 수정
void myKD() {
    struct KDTree* kdTree = initializeKDTree();

    int size, point[K];

    setColor(WHITE);

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("원소를 입력하세요 (각각의 좌표 값): ");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < K; ++j) {
            scanf_s("%d", &point[j]);
        }
        KDinsert(kdTree, point);
    }

    printf("\n전위 순회 결과:\n");
    KDpreorderTraversal(kdTree->root, 0);

    printf("\n중위 순회 결과:\n");
    KDinorderTraversal(kdTree->root, 0);

    printf("\n후위 순회 결과:\n");
    KDpostorderTraversal(kdTree->root, 0);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}
