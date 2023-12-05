#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "BackTrackingTree.h"

#define MAX_SIZE 100
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

bool isValid(struct Maze* maze, int x, int y) {
    return (x >= 0 && x < maze->size && y >= 0 && y < maze->size && maze->maze[x][y] == 0);
}

bool solveMaze(struct Maze* maze, struct Path start, struct Path goal, struct Path* path, int index) {
    if (start.x == goal.x && start.y == goal.y) {
        // 목표 지점에 도달한 경우
        path[index] = start;
        return true;
    }

    if (isValid(maze, start.x, start.y)) {
        // 현재 위치를 경로에 추가
        path[index] = start;

        // 오른쪽으로 이동
        if (solveMaze(maze, (struct Path) { start.x, start.y + 1 }, goal, path, index + 1)) {
            return true;
        }

        // 아래로 이동
        if (solveMaze(maze, (struct Path) { start.x + 1, start.y }, goal, path, index + 1)) {
            return true;
        }

        // 왼쪽으로 이동
        if (solveMaze(maze, (struct Path) { start.x, start.y - 1 }, goal, path, index + 1)) {
            return true;
        }

        // 위로 이동
        if (solveMaze(maze, (struct Path) { start.x - 1, start.y }, goal, path, index + 1)) {
            return true;
        }

        // 현재 위치가 선택한 지점이므로, 다른 경로를 탐색하기 위해 경로에서 제거
        path[index].x = -1;
        path[index].y = -1;
    }

    return false;
}

void printMazeWithPaths(struct Maze* maze, struct Path* paths) {
    for (int i = 0; i < maze->size; ++i) {
        for (int j = 0; j < maze->size; ++j) {
            if (maze->maze[i][j] == 1) {
                printf("1 ");  // 벽
            }
            else {
                bool isPath = false;
                for (int k = 0; k < MAX_SIZE * MAX_SIZE; ++k) {
                    if (paths[k].x == i && paths[k].y == j) {
                        printf("2 ");  // 경로
                        isPath = true;
                        break;
                    }
                }
                if (!isPath) {
                    printf("0 ");  // 이동 가능한 경로
                }
            }
        }
        printf("\n");
    }
}

void inputMaze(struct Maze* maze, struct Path* start, struct Path* goal) {
    printf("미로의 크기를 입력하세요: ");
    scanf_s("%d", &maze->size);

    maze->maze = (int**)malloc(maze->size * sizeof(int*));
    for (int i = 0; i < maze->size; ++i) {
        maze->maze[i] = (int*)malloc(maze->size * sizeof(int));
    }

    printf("미로 정보를 입력하세요 (0: 이동 가능, 1: 벽):\n");
    for (int i = 0; i < maze->size; ++i) {
        for (int j = 0; j < maze->size; ++j) {
            scanf_s("%d", &maze->maze[i][j]);
        }
    }

    printf("시작점을 입력하세요 (x y): ");
    scanf_s("%d %d", &start->x, &start->y);

    printf("목표점을 입력하세요 (x y): ");
    scanf_s("%d %d", &goal->x, &goal->y);
}

void solveMazeWrapper() {
    struct Maze maze;
    struct Path start, goal;
    setColor(WHITE);

    inputMaze(&maze, &start, &goal);

    struct Path* path = (struct Path*)malloc(MAX_SIZE * MAX_SIZE * sizeof(struct Path));

    if (solveMaze(&maze, start, goal, path, 0)) {
        printf("\n경로를 찾았습니다!\n");
        printMazeWithPaths(&maze, path);
    }
    else {
        printf("\n경로를 찾을 수 없습니다.\n");
    }

    // 동적으로 할당한 메모리 해제
    for (int i = 0; i < maze.size; ++i) {
        free(maze.maze[i]);
    }
    free(maze.maze);
    free(path);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}

void myBackTrack() {
    // 미로 찾기 호출
    solveMazeWrapper();
}
