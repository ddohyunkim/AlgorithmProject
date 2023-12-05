#include<stdio.h>
#include "algo.h"
#include "RedBlackTree.h"
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include <stdbool.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define red SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //화면 텍스트 색상을 빨간색으로 설정
#define white SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //화면 텍스트 생상을 기본(흰색)으로 설정
#define N 5 // 도시의 수
#define MAX_V 10

int keyControl();
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);
int infoDraw();
void SelectionSort(int a[], int size);
void bubbleSort(int a[], int size);
void quickSort(int a[], int begin, int end, int size);
void insertionSort(int a[], int size);
void shellSort(int a[], int size);
void mergeSort(int a[], int m, int n);
void radixSort(int a[]);
void heapify(int arr[], int n, int i);
void heapSort(int arr[]);
void printArray(int arr[]);
void inOrder(struct Node* root, int* sortedArr, int* index);
void treeSort(int arr[]);
void pArray(int a[], int size);
int isCyclicUtil(int v, int** graph, int* visited, int* recStack, int size);
int isCyclic(int** graph, int size);
void topologicalSort(int a[], int size);
void countingSort(int a[], int size);
void mySelect();
void myBubble();
void myQuick();
void myInsert();
void myShell();
void myMerge();
void myRadix();
void myHeap();
void myTree();
void myTopological();
void myCounting();


struct Node* createNode(int key);
struct Node* insert(struct Node* root, int key);
void preorderTraversal(struct Node* root);
void inorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
void freeTree(struct Node* root);
void myBinary();

struct RBNode* RBcreateNode(int key);
void RBinsert(struct RBNode** root, int key);
void RBinorderTraversal(struct RBNode* root);
void RBpreorderTraversal(struct RBNode* root);
void RBpostorderTraversal(struct RBNode* root);
void fixInsert(struct RBNode* root, struct RBNode* node);
void leftRotate(struct RBNode* root, struct RBNode* x);
void rightRotate(struct RBNode* root, struct RBNode* y);
void myRedBlack();

struct BTreeNode* BcreateNode(int leaf);
struct BTree* initializeBTree();
void splitChild(struct BTreeNode* parent, int index);
void insertNonFull(struct BTreeNode* node, int key);
void Binsert(struct BTree* tree, int key);
void printBTree(struct BTreeNode* root, int level);
void myB();

struct KDTreeNode* createKDNode(int point[]);
struct KDTree* initializeKDTree();
struct KDTree* initializeKDTree();
void KDinsert(struct KDTree* tree, int point[]);
void printKDTree(struct KDTreeNode* root, int depth);
void KDpreorderTraversal(struct KDTreeNode* root, int depth);
void KDinorderTraversal(struct KDTreeNode* root, int depth);
void KDpostorderTraversal(struct KDTreeNode* root, int depth);
void myKD();

struct RTreeNode* createRNode(int leaf);
struct RTree* initializeRTree();
void RsplitChild(struct RTreeNode* parent, int index);
void RinsertNonFull(struct RTreeNode* node, int key);
void Rinsert(struct RTree* tree, int key);
void printRTree(struct RTreeNode* root, int level);
void myR();

int findParent(int parent[], int i);
void unionSets(int parent[], int x, int y);
int compareEdges(const void* a, const void* b);
void kruskal(struct Graph* graph);
void myKruskal();

int findMinKey(int key[], bool mstSet[], int V);
void prim(struct PGraph* graph);
void myPrim();

int compareMeetings(const void* a, const void* b);
void printMaxMeetings(struct Meeting meetings[], int n);
void myGreed();

bool isValid(struct Maze* maze, int x, int y);
bool solveMaze(struct Maze* maze, struct Path start, struct Path goal, struct Path* path, int index);
void printMazeWithPaths(struct Maze* maze, struct Path* paths);
void inputMaze(struct Maze* maze, struct Path* start, struct Path* goal);
void solveMazeWrapper();
void myBackTrack();

void tsp(int current, int visited, int graph[N][N], int path[N], int path_index, int* min_cost);
void StateSpaceTree(void);
void mySpace();

struct Graph3* createGraph3(int vertices);
void addEdge3(struct Graph3* graph, int src, int dest);
void bfs(struct Graph3* graph, int startVertex);
void BFS();
void myBFS();

struct Node;
struct Graph;
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void dfs(struct Graph* graph, int vertex);
void DFS();

struct Node6;
struct Graph6;
struct Node6* createNode6(int v, int weight);
struct Graph6* createGraph6(int vertices);
void addEdge6(struct Graph6* graph, int src, int dest, int weight);
void printDijkstra(int dist[], int n);
int minDistance(int dist[], int sptSet[], int n);
void dijkstra(struct Graph6* graph, int src);
void Dijkstra();

struct Edge7;
struct Graph7;
struct Graph7* createGraph7(int vertices, int edges);
void printShortestPath(int dist[], int n);
void bellmanFord(struct Graph7* graph, int src);
void BellmanFord();

int V, E;
int adj[MAX_V][MAX_V];
void initAdj();
void floyd();
void myFloyd();

void initAdj2();
void dijkstra2(int start);
void DAG();

struct Node9;
int** createGraph9(int n);
struct Node9* createNode9(int city, int f, int g, int h, struct Node9* parent);
int heuristic(int city, int dest);
void printPath9(struct Node9* current);
void astar(int** graph, int start, int dest, int n);
void aStar();

int finalPath[N]; // 최종 최소 비용 경로를 저장하는 배열
int visited[N];
int graph[N][N];
void printGraph();
void printPath(int path[N]);
int isSafe2(int v, int k, int path[N]);
void tsp2(int path[N], int k, int cost);
void myBranch();

struct Node7;
struct Set;
struct Node7* createNode7(int data);
struct Set* createSet();
void Make_Set(struct Set* set, int data);
struct Node7* Find_Set(struct Set* set, int data);
void Union2(struct Set* set, int x, int y);
void displaySets(struct Set* set);
void myLinked();

struct Node8;
struct Node8* make_set(int x);
struct Node8* find_set(struct Node8* node);
void union_sets(struct Node8* x, struct Node8* y);
void print_sets(struct Node8* nodes[], int n);
void free_memory(struct Node8* nodes[], int n);
void  myTreeSet();

int min2(int a, int b);
void find_min_path(int** matrix, int rows, int cols);
void myPath();

int hash_function2(int key, int array_size);
void insert2(int hash_table[], int key, int value, int array_size);
int get2(int hash_table[], int key, int array_size);
void remove_key2(int hash_table[], int key, int array_size);
int is_empty2(int hash_table[], int key, int array_size);
void print_table2(int hash_table[], int array_size);
void myDiv();

int hash_function(int key, int array_size);
void insert1(int hash_table[], int key, int value, int array_size);
int get(int hash_table[], int key, int array_size);
void remove_key(int hash_table[], int key, int array_size);
int is_empty(int hash_table[], int key, int array_size);
void print_table(int hash_table[], int array_size);
void myMul();


void init() {
    system("mode con cols=120 lines=50 | title ALGORITHM");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = FALSE; //커서를 숨김
    ConsoleCursor.dwSize = 1; //커서 굵기
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
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
void setColor(unsigned short text) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
} //콘솔 텍스트 생상 변경해주는 함수

int main() {
back:
    system("cls"); //콘솔 화면 지우기
    init();
    while (1) {
        titleDraw();

        int menuCode = menuDraw();
        if (menuCode == 0) { //정렬 알고리즘

            int infoCode = infoDraw();
            if (infoCode == 0) {
                system("cls");
                mySelect(); //선택정렬
            }
            else if (infoCode == 1) {
                myBubble(); //버블정렬
            }
            else if (infoCode == 2) {
                myQuick(); //퀵정렬
            }
            else if (infoCode == 3) {
                myInsert(); //삽입정렬
            }
            else if (infoCode == 4) {
                myMerge(); //병합정렬
            }
            else if (infoCode == 5) {
                myRadix(); //기수정렬
            }
            else if (infoCode == 6) {
                myHeap(); //히프정렬
            }
            else if (infoCode == 7) {
                myTree(); //트리정렬
            }
            else if (infoCode == 8) {
                myShell(); //쉘정렬
            }
            else if (infoCode == 9) {
                myTopological(); //위상정렬
            }
            else if (infoCode == 10) {
                myCounting(); //계수정렬
            }
            else if (infoCode == 11) {
                goto back;
            }
        }
        else if (menuCode == 1) { // 트리 알고리즘

            int treeCode = treeDraw();
            if (treeCode == 0) {
                system("cls");
                myBinary(); //이진탐색트리
            }
            else if (treeCode == 1) {
                system("cls");
                myRedBlack(); //레드블랙트리
            }
            else if (treeCode == 2) {
                system("cls");
                myB(); //비트리
            }
            else if (treeCode == 3) {
                system("cls");
                myKD(); //KD트리
            }
            else if (treeCode == 4) {
                system("cls");
                myR(); //R트리
            }
            else if (treeCode == 5) {
                system("cls");
                myKruskal(); //최소신장트리(크루스칼알고리즘)
            }
            else if (treeCode == 6) {
                system("cls");
                myPrim(); //최소신장트리(프림알고리즘)
            }
            else if (treeCode == 7) {
                system("cls");
                myGreed(); //최소신장트리(그리디알고리즘)
            }
            else if (treeCode == 8) {
                system("cls");
                mySpace(); //상태공간트리
            }
            else if (treeCode == 9) {
                system("cls");
                myBackTrack(); //백트래킹
            }
            else if (treeCode == 10) {
                goto back;
            }
        }

        else if (menuCode == 2) { // 그래프 알고리즘

            int graphCode = graphDraw();
            if (graphCode == 0) {
                system("cls");
                myBFS(); //너비우선탐색
            }
            else if (graphCode == 1) {
                system("cls");
                DFS(); //깊이우선탐색
            }
            else if (graphCode == 2) {
                system("cls");
                Dijkstra(); //다익스트라알고리즘
            }
            else if (graphCode == 3) {
                system("cls");
                BellmanFord(); //벨만포드알고리즘
            }
            else if (graphCode == 4) {
                system("cls");
                myFloyd(); //모든쌍최단경로알고리즘
            }
            else if (graphCode == 5) {
                system("cls");
                DAG(); //사이클없는그래프의최단경로
            }
            else if (graphCode == 6) {
                system("cls");
                aStar(); //A*알고리즘
            }
            else if (graphCode == 7) {
                system("cls");
                myBranch(); //한정분기
            }
            else if (graphCode == 8) {
                goto back;
            }

        }

        else if (menuCode == 3) { // 기타 등등

            int etcCode = etcDraw();
            if (etcCode == 0) {
                system("cls");
                myLinked(); //연결리스트를이용한집합의처리
            }
            else if (etcCode == 1) {
                system("cls");
                myTreeSet(); //트리를이용한집합의처리
            }
            else if (etcCode == 2) {
                system("cls");
                myPath(); //동적프로그래밍(행렬경로문제)
            }
            else if (etcCode == 3) {
                system("cls");
                myDiv(); //해시함수(나누기방법)
            }
            else if (etcCode == 4) {
                system("cls");
                myMul(); //해시함수(곱하기방법)
            }
            else if (etcCode == 5) {
                goto back;
            }

            }
        else if (menuCode == 11) { //프로그램 종료
            return 0;
        }
        system("cls");
    }
    return 0;
}

void titleDraw() {
    printf("\n\n\n\n\n\n\n");
    setColor(RED);
    printf("                       #     #      ####    ####     #####    #####   #####   #   #    #       #\n");
    setColor(YELLOW);
    printf("                      # #    #     #       #    #    #    #     #       #     #   #    ##     ##\n");
    setColor(GREEN);
    printf("                     #####   #     #   ##  #    #    ####       #       #     #####    # #   # #\n");
    setColor(BLUE);
    printf("                     #   #   #     #    #  #    #    #   #      #       #     #   #    #  # #  #\n");
    setColor(VIOLET);
    printf("                     #   #   ####   ####    ####     #    #   #####     #     #   #    #   #   #\n");
}
void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
    return - 1;
}
int menuDraw() {
    int x = 50;
    int y = 30;
    gotoxy(x - 5, y - 2);
    setColor(WHITE);
    printf("■■■■■■■■■■■■■");
    gotoxy(x - 5, y - 2);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y - 1);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y + 1);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y + 2);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y + 3);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y + 4);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y + 5);
    setColor(WHITE);
    printf("■");
    gotoxy(x - 5, y + 5);
    setColor(WHITE);
    printf("■■■■■■■■■■■■■");
    gotoxy(x + 19, y - 2);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y - 1);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y + 1);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y + 2);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y + 3);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y + 4);
    setColor(WHITE);
    printf("■");
    gotoxy(x + 19, y + 5);
    setColor(WHITE);
    printf("■");
    gotoxy(x, y);
    setColor(WHITE);
    printf("> 정렬  알고리즘");
    gotoxy(x, y + 1);
    setColor(WHITE);
    printf("  트리  알고리즘");
    gotoxy(x, y + 2);
    setColor(WHITE);
    printf("  그래프 알고리즘");
    gotoxy(x, y + 3);
    setColor(WHITE);
    printf("  기타 등등");
    gotoxy(x, y + 4);
    setColor(WHITE);
    printf("  종료");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 30) {
                setColor(SKYBLUE);
                gotoxy(x, y);
                printf(" ");
                gotoxy(x, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 34) {
                setColor(SKYBLUE);
                gotoxy(x, y);
                printf(" ");
                gotoxy(x, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y - 30;
        }
        }
    }
}
int infoDraw() {
    system("cls");
    int x = 5;
    int y = 0;
    setColor(WHITE);
    gotoxy(x - 2, y);
    printf("> 선택 정렬");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("버블 절렬");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("퀵   정렬");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("삽입 정렬");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("병합 정렬");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("기수 정렬");
    setColor(WHITE);
    gotoxy(x, y + 6);
    printf("히프 정렬");
    setColor(WHITE);
    gotoxy(x, y + 7);
    printf("트리 정렬");
    setColor(WHITE);
    gotoxy(x, y + 8);
    printf("쉘   정렬");
    setColor(WHITE);
    gotoxy(x, y + 9);
    printf("위상 정렬");
    setColor(WHITE);
    gotoxy(x, y + 10);
    printf("계수 정렬");
    setColor(WHITE);
    gotoxy(x, y + 11);
    printf("뒤로 가기");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 0) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 11) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y;
        }
        }
    }
    Sleep(1000);
}
int treeDraw() {
    system("cls");
    int x = 5;
    int y = 0;
    setColor(WHITE);
    gotoxy(x - 2, y);
    printf("> 이진 탐색 트리");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("레드 블랙 트리");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("B 트리");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("KD 트리");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("R 트리");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("최소 신장 트리 (크루스칼 알고리즘)");
    setColor(WHITE);
    gotoxy(x, y + 6);
    printf("최소 신장 트리 (프림 알고리즘)");
    setColor(WHITE);
    gotoxy(x, y + 7);
    printf("최소 신장 트리 (그리디 알고리즘)");
    setColor(WHITE);
    gotoxy(x, y + 8);
    printf("상태 공간 트리");
    setColor(WHITE);
    gotoxy(x, y + 9);
    printf("백트래킹");
    setColor(WHITE);
    gotoxy(x, y + 10);
    printf("뒤로 가기");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 0) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 10) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y;
        }
        }
    }
    Sleep(1000);
}
int graphDraw() {
    system("cls");
    int x = 5;
    int y = 0;
    setColor(WHITE);
    gotoxy(x - 2, y);
    printf("> 너비 우선 탐색");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("깊이 우선 탐색");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("다익스트라 알고리즘");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("벨만-포드 알고리즘");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("모든 쌍 최단경로 알고리즘");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("사이클 없는 그래프의 최단경로");
    setColor(WHITE);
    gotoxy(x, y + 6);
    printf("A* 알고리즘");
    setColor(WHITE);
    gotoxy(x, y + 7);
    printf("한정분기");
    setColor(WHITE);
    gotoxy(x, y + 8);
    printf("뒤로 가기");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 0) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 8) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y;
        }
        }
    }
    Sleep(1000);
}
int etcDraw() {
    system("cls");
    int x = 5;
    int y = 0;
    setColor(WHITE);
    gotoxy(x - 2, y);
    printf("> 연결 리스트를 이용한 집합의 처리");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("트리를 이용한 집합의 처리");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("동적 프로그래밍(행렬 경로 문제)");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("해시 함수(나누기 방법)");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("해시 함수(곱하기 방법)");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("뒤로 가기");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 0) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 5) {
                setColor(SKYBLUE);
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y;
        }
        }
    }
    Sleep(1000);
}