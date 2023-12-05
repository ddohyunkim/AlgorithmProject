#pragma once
#ifndef ALGO_H
#define ALGO_H

extern int size;
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
int main();
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
int keyControl();

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key);
struct Node* insert(struct Node* root, int key);
void preorderTraversal(struct Node* root);
void inorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
void freeTree(struct Node* root);
void myBinary();
#endif