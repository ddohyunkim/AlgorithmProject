#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

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

// 새로운 노드 생성
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


// 이진 탐색 트리 전위 순회
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 이진 탐색 트리 중위 순회
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}


// 이진 탐색 트리 후위 순회
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void myBinary() {
    struct Node* root = NULL;
    int size;
    setColor(WHITE);

    // 사용자로부터 원하는 원소 개수 입력
    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    // 사용자로부터 원소 입력 및 이진 탐색 트리에 삽입
    printf("원소를 입력하세요: ");
    for (int i = 0; i < size; ++i) {
        int element;
        scanf_s("%d", &element);
        root = insert(root, element);
    }

    // 전위 순회로 트리 출력
    printf("전위 순회 결과: ");
    preorderTraversal(root);
    printf("\n");

    // 중위 순회로 트리 출력
    printf("중위 순회 결과: ");
    inorderTraversal(root);
    printf("\n");

    // 후위 순회로 트리 출력
    printf("후위 순회 결과: ");
    postorderTraversal(root);
    printf("\n");

    // 메모리 해제
    free(root);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}
