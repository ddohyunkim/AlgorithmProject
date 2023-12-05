#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Astar.h"

#define MAX_CITIES 10
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

struct Node9 {
    int city;
    int f;
    int g;
    int h;
    struct Node9* parent;
};

int** createGraph9(int n) {
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
    }
    return graph;
}

struct Node9* createNode9(int city, int f, int g, int h, struct Node9* parent) {
    struct Node9* newNode = (struct Node9*)malloc(sizeof(struct Node9));
    newNode->city = city;
    newNode->f = f;
    newNode->g = g;
    newNode->h = h;
    newNode->parent = parent;
    return newNode;
}

int heuristic(int city, int dest) {
    return 0; // �޸���ƽ �Լ�, ���⼭�� ������ 0���� �����մϴ�.
}

void printPath9(struct Node9* current) {
    if (current == NULL) {
        return;
    }
    printPath9(current->parent);
    printf("%d ", current->city);
}

void astar(int** graph, int start, int dest, int n) {
    struct Node9* startNode = createNode9(start, 0, 0, 0, NULL);
    startNode->h = heuristic(start, dest);

    while (startNode != NULL) {
        if (startNode->city == dest) {
            printf("�ִ� ���: ");
            printPath9(startNode);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (graph[startNode->city][i] != 0) {
                int g = startNode->g + graph[startNode->city][i];
                int h = heuristic(i, dest);
                int f = g + h;
                struct Node9* newNode = createNode9(i, f, g, h, startNode);
                newNode->parent = startNode->parent; // ����: 'next' ��� 'parent'�� ����
                startNode->parent = newNode; // ����: 'next' ��� 'parent'�� ����
            }
        }

        startNode = startNode->parent;
    }

    printf("�ִ� ��ΰ� �������� �ʽ��ϴ�.\n");
}

void aStar() {
    setColor(WHITE);
    int close = 1;
    int** graph;
    int numCities, start, dest;

    printf("������ ���� �Է��ϼ��� (�ִ� %d��): ", MAX_CITIES);
    scanf_s("%d", &numCities);

    graph = createGraph9(numCities);

    printf("���� ���� �Ÿ��� �Է��ϼ���:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf_s("%d", &graph[i][j]);
        }
    }

    printf("��� ���ø� �Է��ϼ��� (0���� %d����): ", numCities - 1);
    scanf_s("%d", &start);
    printf("���� ���ø� �Է��ϼ��� (0���� %d����): ", numCities - 1);
    scanf_s("%d", &dest);

    astar(graph, start, dest, numCities);

    for (int i = 0; i < numCities; i++) {
        free(graph[i]);
    }
    free(graph);

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
