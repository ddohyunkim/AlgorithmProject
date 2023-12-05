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


// ������ ǥ���� Ʈ�� ��� ����ü ����
struct Node8 {
    int data;
    struct Node8* parent;
};

// ��� ���� �Լ�
struct Node8* make_set(int x) {
    struct Node8* new_node = (struct Node8*)malloc(sizeof(struct Node8));
    new_node->data = x;
    new_node->parent = new_node;  // ó������ �ڽ��� ������ ��ǥ
    return new_node;
}

// ������ ��ǥ ��带 ã�� �Լ�
struct Node8* find_set(struct Node8* node) {
    if (node != node->parent) {
        node->parent = find_set(node->parent);  // ��� ����
    }
    return node->parent;
}

// �� ������ ��ġ�� �Լ�
void union_sets(struct Node8* x, struct Node8* y) {
    struct Node8* x_rep = find_set(x);
    struct Node8* y_rep = find_set(y);
    if (x_rep != y_rep) {
        y_rep->parent = x_rep;  // �� ������ ��ǥ�� �ٸ� ������ ��ǥ�� �ڽ����� ����
    }
}

// ���� ��� �Լ� (��ǥ ��常 ���)
void print_sets(struct Node8* nodes[], int n) {
    printf("�� ������ ��ǥ ���:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d -> %d\n", nodes[i]->data, find_set(nodes[i])->data);
    }
}

// �޸� ���� �Լ�
void free_memory(struct Node8* nodes[], int n) {
    for (int i = 0; i < n; ++i) {
        free(nodes[i]);
    }
}

// ���� �Լ�
void myTreeSet() {
    setColor(WHITE);
    int close = 1;
    int num_elements;
    printf("������ ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &num_elements);

    struct Node8* nodes[20];

    printf("%d���� ���Ҹ� �Է��ϼ���:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int x;
        scanf_s("%d", &x);
        nodes[i] = make_set(x);
    }

    print_sets(nodes, num_elements);  // �� ������ ��ǥ ���

    int choice, x, y;
    printf("\n�� ���� ��ġ��\n");
    printf("��ĥ �� ���Ҹ� �����ϼ���: ");
    scanf_s("%d %d", &x, &y);
    union_sets(nodes[x - 1], nodes[y - 1]);
    printf("��ģ ���� �� ������ ��ǥ ���:\n");
    print_sets(nodes, num_elements);
        
    // �޸� ����
    free_memory(nodes, num_elements);

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
