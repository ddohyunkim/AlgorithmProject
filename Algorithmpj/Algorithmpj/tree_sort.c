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

// 이진 탐색 트리 노드 정의
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// 새로운 노드 생성
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// 이진 탐색 트리에 노드 추가
struct Node* insert(struct Node* root, int key) {
    // 트리가 비어있으면 새로운 노드를 root로 설정
    if (root == NULL) return newNode(key);

    // 그렇지 않으면 적절한 위치에 삽입
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// 중위 순회를 통한 정렬
void inOrder(struct Node* root, int* sortedArr, int* index) {
    if (root != NULL) {
        inOrder(root->left, sortedArr, index);
        sortedArr[*index] = root->key;
        (*index)++;
        inOrder(root->right, sortedArr, index);
    }
}

// 트리 정렬 함수
void treeSort(int arr[]) {
    struct Node* root = NULL;

    // 이진 탐색 트리에 배열의 요소 추가
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    // 중위 순회를 통한 정렬된 결과 얻기
    int index = 0;
    inOrder(root, arr, &index);
}

void myTree() {
    int list[MAX];
    setColor(WHITE);

    printf("원소 개수를 입력하세요: ");
    scanf_s("%d", &size);

    printf("정렬할 원소를 입력하세요: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &list[i]);
    }

    printf("\n정렬할 원소 : ");
    for (int i = 0; i < size; i++) printf("%3d ", list[i]);
    printf("\n<<<<<<<<<< 트리 정렬 수행 >>>>>>>>>>\n");

    treeSort(list);

    // 정렬된 결과 출력
    printf("\n정렬된 결과: ");
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
