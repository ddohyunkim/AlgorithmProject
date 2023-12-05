#pragma once
#ifndef BACKTRACKING_TREE_H
#define BACKTRACKING_TREE_H

#include <stdbool.h>

#define MAX_SIZE 100

// 미로 구조체 정의
struct Maze {
    int size;
    int** maze;
};

struct Path {
    int x;
    int y;
};

bool isValid(struct Maze* maze, int x, int y);
bool solveMaze(struct Maze* maze, struct Path start, struct Path goal, struct Path* path, int index);
void printMazeWithPaths(struct Maze* maze, struct Path* paths);
void inputMaze(struct Maze* maze, struct Path* start, struct Path* goal);
void solveMazeWrapper();
void myBackTrack();

int main();
int keyControl();
#endif