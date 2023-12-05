#pragma once
#ifndef DIV_H
#define DIV_H

int hash_function2(int key, int array_size);
void insert2(int hash_table[], int key, int value, int array_size);
int get2(int hash_table[], int key, int array_size);
void remove_key2(int hash_table[], int key, int array_size);
int is_empty2(int hash_table[], int key, int array_size);
void print_table2(int hash_table[], int array_size);
void myDiv();

int main();
int keyControl();
#endif
