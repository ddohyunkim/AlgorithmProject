#include <stdio.h>
#include <stdlib.h>

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

struct Node7 {
    int data;
    struct Node7* next;
};

struct Set {
    struct Node7* head;
};

struct Node7* createNode7(int data) {
    struct Node7* newNode = (struct Node7*)malloc(sizeof(struct Node7));
    if (newNode == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Set* createSet() {
    struct Set* newSet = (struct Set*)malloc(sizeof(struct Set));
    if (newSet == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    newSet->head = NULL;
    return newSet;
}

void Make_Set(struct Set* set, int data) {
    struct Node7* newNode = createNode7(data);
    newNode->next = set->head;
    set->head = newNode;
}

struct Node7* Find_Set(struct Set* set, int data) {
    struct Node7* temp = set->head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Union2(struct Set* set, int x, int y) {
    struct Node7* nodeX = Find_Set(set, x);
    struct Node7* nodeY = Find_Set(set, y);

    if (nodeX == NULL || nodeY == NULL) {
        printf("���Ҹ� ã�� �� �����ϴ�.\n");
        return;
    }

    if (nodeX != nodeY) {
        struct Node7* temp = set->head;
        while (temp != NULL) {
            if (temp->data == nodeY->data) {
                temp->data = nodeX->data;
            }
            temp = temp->next;
        }
    }
    else {
        printf("�� ���Ұ� �̹� ������ ���տ� ���� �ֽ��ϴ�.\n");
    }
}

void displaySets(struct Set* set) {
    struct Node7* temp = set->head;
    printf("���� ����:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void myLinked() {
    setColor(WHITE);
    int close = 1;
    struct Set* set = createSet();
    int numElements;
    printf("������ ��� ��: ");
    scanf_s("%d", &numElements);

    printf("������ ��Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < numElements; ++i) {
        int element;
        scanf_s("%d", &element);
        Make_Set(set, element);
    }

    int x, y;
    printf("������ ��ġ�� ���� �� ���� �Է�: ");
    scanf_s("%d %d", &x, &y);
    Union2(set, x, y);

    displaySets(set);

    free(set); // �޸� ����

    int keyPressed;
    while (1) {
        keyPressed = keyControl();
        if (keyPressed == SUBMIT) {
            break;
        }
    }

    if (keyPressed == SUBMIT) {
        main();  // main �Լ� ȣ��
    }
}


