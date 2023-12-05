#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Floyd.h"

#define MAX_V 10
#define MIN(a,b) a<b ? a:b
#define INF 987654321
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

// 플로이드 워셜 알고리즘
int V, E;
int adj[MAX_V][MAX_V];
void initAdj() {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            adj[i][j] = INF;
            if (i == j)adj[i][j] = 0;
        }
}
void floyd() {
    int k, j, i;

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
}


void myFloyd() {
    setColor(WHITE);
    int close = 1;
    int i, j;
    printf("정점 개수 :");
    scanf_s("%d", &V);
    printf("간선 개수 :");
    scanf_s("%d", &E);

    initAdj();

    printf("정점 연결( 정점1 정점2 비용) \n");
    for (i = 0; i < E; i++) {
        int v1, v2, cost;
        scanf_s("%d %d %d", &v1, &v2, &cost);
        adj[v1][v2] = adj[v2][v1] = cost;
    }


    floyd();

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++)
            printf("%d~%d까지의 최단거리:%d\n", i, j, adj[i][j]);
        printf("\n\n");
    }

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
