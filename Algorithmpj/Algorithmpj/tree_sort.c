#include <stdio.h>
#include <stdlib.h>

#define SUBMIT 4
#define MAX 30

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

extern int size;

// ���� Ž�� Ʈ�� ��� ����
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// ���ο� ��� ����
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// ���� Ž�� Ʈ���� ��� �߰�
struct Node* insert(struct Node* root, int key) {
    // Ʈ���� ��������� ���ο� ��带 root�� ����
    if (root == NULL) return newNode(key);

    // �׷��� ������ ������ ��ġ�� ����
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// ���� ��ȸ�� ���� ����
void inOrder(struct Node* root, int* sortedArr, int* index) {
    if (root != NULL) {
        inOrder(root->left, sortedArr, index);
        sortedArr[*index] = root->key;
        (*index)++;
        inOrder(root->right, sortedArr, index);
    }
}

// Ʈ�� ���� �Լ�
void treeSort(int arr[]) {
    struct Node* root = NULL;

    // ���� Ž�� Ʈ���� �迭�� ��� �߰�
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    // ���� ��ȸ�� ���� ���ĵ� ��� ���
    int index = 0;
    inOrder(root, arr, &index);
}

void myTree() {
    int list[MAX];
    setColor(WHITE);

    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &size);

    printf("������ ���Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n������ ���� : ");
    for (int i = 0; i < size; i++) printf("%3d ", list[i]);
    printf("\n<<<<<<<<<< Ʈ�� ���� ���� >>>>>>>>>>\n");

    treeSort(list);

    // ���ĵ� ��� ���
    printf("\n���ĵ� ���: ");
    for (int i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main();
        }
    }
}
