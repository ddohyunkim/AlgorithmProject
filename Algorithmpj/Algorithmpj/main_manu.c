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
#define red SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //ȭ�� �ؽ�Ʈ ������ ���������� ����
#define white SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //ȭ�� �ؽ�Ʈ ������ �⺻(���)���� ����
#define N 5 // ������ ��
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

int finalPath[N]; // ���� �ּ� ��� ��θ� �����ϴ� �迭
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
    ConsoleCursor.bVisible = FALSE; //Ŀ���� ����
    ConsoleCursor.dwSize = 1; //Ŀ�� ����
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
} //�ܼ� �ؽ�Ʈ ���� �������ִ� �Լ�

int main() {
back:
    system("cls"); //�ܼ� ȭ�� �����
    init();
    while (1) {
        titleDraw();

        int menuCode = menuDraw();
        if (menuCode == 0) { //���� �˰���

            int infoCode = infoDraw();
            if (infoCode == 0) {
                system("cls");
                mySelect(); //��������
            }
            else if (infoCode == 1) {
                myBubble(); //��������
            }
            else if (infoCode == 2) {
                myQuick(); //������
            }
            else if (infoCode == 3) {
                myInsert(); //��������
            }
            else if (infoCode == 4) {
                myMerge(); //��������
            }
            else if (infoCode == 5) {
                myRadix(); //�������
            }
            else if (infoCode == 6) {
                myHeap(); //��������
            }
            else if (infoCode == 7) {
                myTree(); //Ʈ������
            }
            else if (infoCode == 8) {
                myShell(); //������
            }
            else if (infoCode == 9) {
                myTopological(); //��������
            }
            else if (infoCode == 10) {
                myCounting(); //�������
            }
            else if (infoCode == 11) {
                goto back;
            }
        }
        else if (menuCode == 1) { // Ʈ�� �˰���

            int treeCode = treeDraw();
            if (treeCode == 0) {
                system("cls");
                myBinary(); //����Ž��Ʈ��
            }
            else if (treeCode == 1) {
                system("cls");
                myRedBlack(); //�����Ʈ��
            }
            else if (treeCode == 2) {
                system("cls");
                myB(); //��Ʈ��
            }
            else if (treeCode == 3) {
                system("cls");
                myKD(); //KDƮ��
            }
            else if (treeCode == 4) {
                system("cls");
                myR(); //RƮ��
            }
            else if (treeCode == 5) {
                system("cls");
                myKruskal(); //�ּҽ���Ʈ��(ũ�罺Į�˰���)
            }
            else if (treeCode == 6) {
                system("cls");
                myPrim(); //�ּҽ���Ʈ��(�����˰���)
            }
            else if (treeCode == 7) {
                system("cls");
                myGreed(); //�ּҽ���Ʈ��(�׸���˰���)
            }
            else if (treeCode == 8) {
                system("cls");
                mySpace(); //���°���Ʈ��
            }
            else if (treeCode == 9) {
                system("cls");
                myBackTrack(); //��Ʈ��ŷ
            }
            else if (treeCode == 10) {
                goto back;
            }
        }

        else if (menuCode == 2) { // �׷��� �˰���

            int graphCode = graphDraw();
            if (graphCode == 0) {
                system("cls");
                myBFS(); //�ʺ�켱Ž��
            }
            else if (graphCode == 1) {
                system("cls");
                DFS(); //���̿켱Ž��
            }
            else if (graphCode == 2) {
                system("cls");
                Dijkstra(); //���ͽ�Ʈ��˰���
            }
            else if (graphCode == 3) {
                system("cls");
                BellmanFord(); //��������˰���
            }
            else if (graphCode == 4) {
                system("cls");
                myFloyd(); //�����ִܰ�ξ˰���
            }
            else if (graphCode == 5) {
                system("cls");
                DAG(); //����Ŭ���±׷������ִܰ��
            }
            else if (graphCode == 6) {
                system("cls");
                aStar(); //A*�˰���
            }
            else if (graphCode == 7) {
                system("cls");
                myBranch(); //�����б�
            }
            else if (graphCode == 8) {
                goto back;
            }

        }

        else if (menuCode == 3) { // ��Ÿ ���

            int etcCode = etcDraw();
            if (etcCode == 0) {
                system("cls");
                myLinked(); //���Ḯ��Ʈ���̿���������ó��
            }
            else if (etcCode == 1) {
                system("cls");
                myTreeSet(); //Ʈ�����̿���������ó��
            }
            else if (etcCode == 2) {
                system("cls");
                myPath(); //�������α׷���(��İ�ι���)
            }
            else if (etcCode == 3) {
                system("cls");
                myDiv(); //�ؽ��Լ�(��������)
            }
            else if (etcCode == 4) {
                system("cls");
                myMul(); //�ؽ��Լ�(���ϱ���)
            }
            else if (etcCode == 5) {
                goto back;
            }

            }
        else if (menuCode == 11) { //���α׷� ����
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
    printf("��������������");
    gotoxy(x - 5, y - 2);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y - 1);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y + 1);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y + 2);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y + 3);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y + 4);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y + 5);
    setColor(WHITE);
    printf("��");
    gotoxy(x - 5, y + 5);
    setColor(WHITE);
    printf("��������������");
    gotoxy(x + 19, y - 2);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y - 1);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y + 1);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y + 2);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y + 3);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y + 4);
    setColor(WHITE);
    printf("��");
    gotoxy(x + 19, y + 5);
    setColor(WHITE);
    printf("��");
    gotoxy(x, y);
    setColor(WHITE);
    printf("> ����  �˰���");
    gotoxy(x, y + 1);
    setColor(WHITE);
    printf("  Ʈ��  �˰���");
    gotoxy(x, y + 2);
    setColor(WHITE);
    printf("  �׷��� �˰���");
    gotoxy(x, y + 3);
    setColor(WHITE);
    printf("  ��Ÿ ���");
    gotoxy(x, y + 4);
    setColor(WHITE);
    printf("  ����");
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
    printf("> ���� ����");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("���� ����");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("��   ����");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("���� ����");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("���� ����");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("��� ����");
    setColor(WHITE);
    gotoxy(x, y + 6);
    printf("���� ����");
    setColor(WHITE);
    gotoxy(x, y + 7);
    printf("Ʈ�� ����");
    setColor(WHITE);
    gotoxy(x, y + 8);
    printf("��   ����");
    setColor(WHITE);
    gotoxy(x, y + 9);
    printf("���� ����");
    setColor(WHITE);
    gotoxy(x, y + 10);
    printf("��� ����");
    setColor(WHITE);
    gotoxy(x, y + 11);
    printf("�ڷ� ����");
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
    printf("> ���� Ž�� Ʈ��");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("���� �� Ʈ��");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("B Ʈ��");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("KD Ʈ��");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("R Ʈ��");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("�ּ� ���� Ʈ�� (ũ�罺Į �˰���)");
    setColor(WHITE);
    gotoxy(x, y + 6);
    printf("�ּ� ���� Ʈ�� (���� �˰���)");
    setColor(WHITE);
    gotoxy(x, y + 7);
    printf("�ּ� ���� Ʈ�� (�׸��� �˰���)");
    setColor(WHITE);
    gotoxy(x, y + 8);
    printf("���� ���� Ʈ��");
    setColor(WHITE);
    gotoxy(x, y + 9);
    printf("��Ʈ��ŷ");
    setColor(WHITE);
    gotoxy(x, y + 10);
    printf("�ڷ� ����");
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
    printf("> �ʺ� �켱 Ž��");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("���� �켱 Ž��");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("���ͽ�Ʈ�� �˰���");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("����-���� �˰���");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("��� �� �ִܰ�� �˰���");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("����Ŭ ���� �׷����� �ִܰ��");
    setColor(WHITE);
    gotoxy(x, y + 6);
    printf("A* �˰���");
    setColor(WHITE);
    gotoxy(x, y + 7);
    printf("�����б�");
    setColor(WHITE);
    gotoxy(x, y + 8);
    printf("�ڷ� ����");
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
    printf("> ���� ����Ʈ�� �̿��� ������ ó��");
    setColor(WHITE);
    gotoxy(x, y + 1);
    printf("Ʈ���� �̿��� ������ ó��");
    setColor(WHITE);
    gotoxy(x, y + 2);
    printf("���� ���α׷���(��� ��� ����)");
    setColor(WHITE);
    gotoxy(x, y + 3);
    printf("�ؽ� �Լ�(������ ���)");
    setColor(WHITE);
    gotoxy(x, y + 4);
    printf("�ؽ� �Լ�(���ϱ� ���)");
    setColor(WHITE);
    gotoxy(x, y + 5);
    printf("�ڷ� ����");
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