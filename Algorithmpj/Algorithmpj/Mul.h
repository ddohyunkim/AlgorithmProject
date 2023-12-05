#pragma once
#ifndef MUL_H
#define MUL_H

int hash_function(int key, int array_size);
void insert1(int hash_table[], int key, int value, int array_size);
int get(int hash_table[], int key, int array_size);
void remove_key(int hash_table[], int key, int array_size);
int is_empty(int hash_table[], int key, int array_size);
void print_table(int hash_table[], int array_size);
void myMul();

int main();
int keyControl();
#endif
