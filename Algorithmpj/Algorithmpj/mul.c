#include <stdio.h>
#include <stdlib.h>

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


// �ؽ� �Լ� - ���ϱ�
int hash_function(int key, int array_size) {
    float A = 0.618; 
    return (int)(array_size * ((key * A) - (int)(key * A)));
}

void insert1(int hash_table[], int key, int value, int array_size) {
    int index = hash_function(key, array_size);
    hash_table[index] = value;
    printf("Ű %d�� �ε��� %d�� �ؽ̵Ǿ����ϴ�.\n", key, index);
}

int get(int hash_table[], int key, int array_size) {
    int index = hash_function(key, array_size);
    return hash_table[index];
}

void remove_key(int hash_table[], int key, int array_size) {
    int index = hash_function(key, array_size);
    hash_table[index] = -1; 
    printf("Ű %d�� �ε��� %d���� �����Ǿ����ϴ�.\n", key, index);
}

int is_empty(int hash_table[], int key, int array_size) {
    int index = hash_function(key, array_size);
    return (hash_table[index] == -1);
}

void print_table(int hash_table[], int array_size) {
    printf("\nHash Table:\n");
    for (int i = 0; i < array_size; ++i) {
        printf("[%d] = %d\n", i, hash_table[i]);
    }
}

void myMul() {
    setColor(WHITE);
    int close = 1;
    int array_size;

    printf("�ؽ� ���̺��� ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &array_size);

    int* hash_table = (int*)malloc(array_size * sizeof(int));

    printf("Ű-�� ���� ������ �Է��ϼ���: ");
    int num_pairs;
    scanf_s("%d", &num_pairs);

    printf("Ű-�� ���� �Է��ϼ���:\n");
    for (int i = 0; i < num_pairs; ++i) {
        int key, value;
        scanf_s("%d %d", &key, &value);
        insert1(hash_table, key, value, array_size);
    }

    printf("ã���� �ϴ� Ű�� �Է��ϼ���: ");
    int key_to_find;
    scanf_s("%d", &key_to_find);

    int found_value = get(hash_table, key_to_find, array_size);
    printf("Ű %d�� �ش��ϴ� ��: %d\n", key_to_find, found_value);

    printf("������ Ű�� �Է��ϼ���: ");
    int key_to_remove;
    scanf_s("%d", &key_to_remove);
    remove_key(hash_table, key_to_remove, array_size);

    printf("%d�� �����Ǿ����� Ȯ���մϴ�.: %s\n", key_to_remove, is_empty(hash_table, key_to_remove, array_size) ? "Yes" : "No");
    print_table(hash_table, array_size);

    free(hash_table);

    int keyPressed;
    while (1) {
        keyPressed = keyControl();
        if (keyPressed == SUBMIT) {
            break;
        }
    }

    if (keyPressed == SUBMIT) {
        main();  // main �Լ� ȣ��
    }
}