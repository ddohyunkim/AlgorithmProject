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
        // ��ǥ ������ ������ ���
        path[index] = start;
        return true;
    }

    if (isValid(maze, start.x, start.y)) {
        // ���� ��ġ�� ��ο� �߰�
        path[index] = start;

        // ���������� �̵�
        if (solveMaze(maze, (struct Path) { start.x, start.y + 1 }, goal, path, index + 1)) {
            return true;
        }

        // �Ʒ��� �̵�
        if (solveMaze(maze, (struct Path) { start.x + 1, start.y }, goal, path, index + 1)) {
            return true;
        }

        // �������� �̵�
        if (solveMaze(maze, (struct Path) { start.x, start.y - 1 }, goal, path, index + 1)) {
            return true;
        }

        // ���� �̵�
        if (solveMaze(maze, (struct Path) { start.x - 1, start.y }, goal, path, index + 1)) {
            return true;
        }

        // ���� ��ġ�� ������ �����̹Ƿ�, �ٸ� ��θ� Ž���ϱ� ���� ��ο��� ����
        path[index].x = -1;
        path[index].y = -1;
    }

    return false;
}

void printMazeWithPaths(struct Maze* maze, struct Path* paths) {
    for (int i = 0; i < maze->size; ++i) {
        for (int j = 0; j < maze->size; ++j) {
            if (maze->maze[i][j] == 1) {
                printf("1 ");  // ��
            }
            else {
                bool isPath = false;
                for (int k = 0; k < MAX_SIZE * MAX_SIZE; ++k) {
                    if (paths[k].x == i && paths[k].y == j) {
                        printf("2 ");  // ���
                        isPath = true;
                        break;
                    }
                }
                if (!isPath) {
                    printf("0 ");  // �̵� ������ ���
                }
            }
        }
        printf("\n");
    }
}

void inputMaze(struct Maze* maze, struct Path* start, struct Path* goal) {
    printf("�̷��� ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &maze->size);

    maze->maze = (int**)malloc(maze->size * sizeof(int*));
    for (int i = 0; i < maze->size; ++i) {
        maze->maze[i] = (int*)malloc(maze->size * sizeof(int));
    }

    printf("�̷� ������ �Է��ϼ��� (0: �̵� ����, 1: ��):\n");
    for (int i = 0; i < maze->size; ++i) {
        for (int j = 0; j < maze->size; ++j) {
            scanf_s("%d", &maze->maze[i][j]);
        }
    }

    printf("�������� �Է��ϼ��� (x y): ");
    scanf_s("%d %d", &start->x, &start->y);

    printf("��ǥ���� �Է��ϼ��� (x y): ");
    scanf_s("%d %d", &goal->x, &goal->y);
}

void solveMazeWrapper() {
    struct Maze maze;
    struct Path start, goal;
    setColor(WHITE);

    inputMaze(&maze, &start, &goal);

    struct Path* path = (struct Path*)malloc(MAX_SIZE * MAX_SIZE * sizeof(struct Path));

    if (solveMaze(&maze, start, goal, path, 0)) {
        printf("\n��θ� ã�ҽ��ϴ�!\n");
        printMazeWithPaths(&maze, path);
    }
    else {
        printf("\n��θ� ã�� �� �����ϴ�.\n");
    }

    // �������� �Ҵ��� �޸� ����
    for (int i = 0; i < maze.size; ++i) {
        free(maze.maze[i]);
    }
    free(maze.maze);
    free(path);

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main �Լ� ȣ��
        }
    }
}

void myBackTrack() {
    // �̷� ã�� ȣ��
    solveMazeWrapper();
}
