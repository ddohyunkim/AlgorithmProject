#include <stdio.h>
#include "StateSpaceTree.h"

#define N 5 // 도시의 수
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

// 상태 공간 트리를 통해 TSP의 진행 상태를 각각 노드로 나타냄

void tsp(int current, int visited, int graph[N][N], int path[N], int path_index, int* min_cost) {
    if (visited == (1 << N) - 1) { // 모든 도시를 방문했을 때
        int total_cost = graph[current][0]; // 시작 도시로 돌아가는 비용
        printf("경로: 0");
        for (int i = 1; i <= path_index; ++i) {
            printf(" -> %d", path[i]);
            total_cost += graph[path[i - 1]][path[i]];
        }
        total_cost += graph[path[path_index]][0];
        printf(" -> 0 (총 비용: %d)\n", total_cost);

        if (total_cost < *min_cost) {
            *min_cost = total_cost;
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!(visited & (1 << i))) { // i번째 도시를 방문하지 않았을 때
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

    int path[N]; // 경로 저장 배열
    path[0] = 0; // 시작 도시는 0번 도시로 가정
    int min_cost = 999999; // 최소 비용 초기화

    printf("\n도시 간 비용 그래프:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nTSP 경로 상태:\n");
    tsp(0, 1, graph, path, 0, &min_cost);

    printf("\n최소 비용: %d\n", min_cost);

    fflush(stdin); // 키 입력 버퍼를 비워줌

    int keyPressed;
    while (1) {
        keyPressed = keyControl();
        if (keyPressed == SUBMIT) {
            break;
        }
    }

    if (keyPressed == SUBMIT) {
        main();  // main 함수 호출
    }
}

void mySpace() {
    StateSpaceTree();
}