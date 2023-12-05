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

// ���ο� ��� ����
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


// ���� Ž�� Ʈ�� ���� ��ȸ
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// ���� Ž�� Ʈ�� ���� ��ȸ
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}


// ���� Ž�� Ʈ�� ���� ��ȸ
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

    // ����ڷκ��� ���ϴ� ���� ���� �Է�
    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    // ����ڷκ��� ���� �Է� �� ���� Ž�� Ʈ���� ����
    printf("���Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < size; ++i) {
        int element;
        scanf_s("%d", &element);
        root = insert(root, element);
    }

    // ���� ��ȸ�� Ʈ�� ���
    printf("���� ��ȸ ���: ");
    preorderTraversal(root);
    printf("\n");

    // ���� ��ȸ�� Ʈ�� ���
    printf("���� ��ȸ ���: ");
    inorderTraversal(root);
    printf("\n");

    // ���� ��ȸ�� Ʈ�� ���
    printf("���� ��ȸ ���: ");
    postorderTraversal(root);
    printf("\n");

    // �޸� ����
    free(root);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main �Լ� ȣ��
        }
    }
}
