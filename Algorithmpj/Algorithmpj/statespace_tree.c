#include <stdio.h>
#include "StateSpaceTree.h"

#define N 5 // ������ ��
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

// ���� ���� Ʈ���� ���� TSP�� ���� ���¸� ���� ���� ��Ÿ��

void tsp(int current, int visited, int graph[N][N], int path[N], int path_index, int* min_cost) {
    if (visited == (1 << N) - 1) { // ��� ���ø� �湮���� ��
        int total_cost = graph[current][0]; // ���� ���÷� ���ư��� ���
        printf("���: 0");
        for (int i = 1; i <= path_index; ++i) {
            printf(" -> %d", path[i]);
            total_cost += graph[path[i - 1]][path[i]];
        }
        total_cost += graph[path[path_index]][0];
        printf(" -> 0 (�� ���: %d)\n", total_cost);

        if (total_cost < *min_cost) {
            *min_cost = total_cost;
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!(visited & (1 << i))) { // i��° ���ø� �湮���� �ʾ��� ��
            path[path_index + 1] = i;
            tsp(i, visited | (1 << i), graph, path, path_index + 1, min_cost);
        }
    }
}

void StateSpaceTree() {
    setColor(WHITE);
    int close = 1;
    int graph[N][N] = {
        {0, 10, 10, 30, 25},
        {10, 0, 14, 21, 10},
        {10, 18, 0, 7, 9},
        {8, 11, 7, 0, 3},
        {14, 10, 10, 3, 0}
    };

    int path[N]; // ��� ���� �迭
    path[0] = 0; // ���� ���ô� 0�� ���÷� ����
    int min_cost = 999999; // �ּ� ��� �ʱ�ȭ

    printf("\n���� �� ��� �׷���:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nTSP ��� ����:\n");
    tsp(0, 1, graph, path, 0, &min_cost);

    printf("\n�ּ� ���: %d\n", min_cost);

    fflush(stdin); // Ű �Է� ���۸� �����

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

void mySpace() {
    StateSpaceTree();
}