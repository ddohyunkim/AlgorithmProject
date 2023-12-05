#include <stdio.h>
#include <stdlib.h>

#define K 2
#define SUBMIT 4

enum {
    BLACK, DARK_BLUE, DARK_GREEN, DARK_SKYBLUE, DARK_RED, DARK_VOILET, DARK_YELLOW,
    GRAY, DARK_GRAY, BLUE, GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE,
};

struct KDTreeNode {
    int point[K];
    struct KDTreeNode* left, * right;
};

struct KDTree {
    struct KDTreeNode* root;
};

void setColor(int color) {
    // 색상 설정 함수 (필요에 따라 구현)
}

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

void insert(struct KDTree* tree, int point[]) {
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

void myKD() {
    struct KDTree* kdTree = initializeKDTree();

    int size, point[K];

    setColor(WHITE);

    printf("원소 개수를 입력하세요: ");
    scanf("%d", &size);

    printf("원소를 입력하세요 (각각의 좌표 값): ");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < K; ++j) {
            scanf("%d", &point[j]);
        }
        insert(kdTree, point);
    }

    printf("\n최종 K-D 트리 상태:\n");
    printKDTree(kdTree->root, 0);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}
