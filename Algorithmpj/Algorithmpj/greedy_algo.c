#include <stdio.h>
#include <stdlib.h>
#include "KruskalAlgo.h"

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


// �� ȸ�Ǹ� ���Ͽ� �����ϱ� ���� �� �Լ�
int compareMeetings(const void* a, const void* b) {
    return ((struct Meeting*)a)->end - ((struct Meeting*)b)->end;
}

// �׸��� �˰����� ����Ͽ� �ִ�� ������ �� �ִ� ȸ�Ǹ� ����ϴ� �Լ�
void printMaxMeetings(struct Meeting meetings[], int n) {
    // ȸ�Ǹ� ������ �ð��� �������� ����
    qsort(meetings, n, sizeof(struct Meeting), compareMeetings);

    printf("�ִ�� ������ �� �ִ� ȸ��:\n");

    // ù ��° ȸ�Ǵ� �׻� ����
    int i = 0;
    printf("ȸ�� %d: ���� �ð� = %d, ������ �ð� = %d\n", meetings[i].id, meetings[i].start, meetings[i].end);

    // ������ ȸ���� ������ �ð����� �ڿ� �����ϴ� ȸ�Ǹ� ����
    for (int j = 1; j < n; j++) {
        if (meetings[j].start >= meetings[i].end) {
            printf("ȸ�� %d: ���� �ð� = %d, ������ �ð� = %d\n", meetings[j].id, meetings[j].start, meetings[j].end);
            i = j;
        }
    }
}

void myGreed() {
    int n;
    setColor(WHITE);

    printf("ȸ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &n);

    struct Meeting* meetings = (struct Meeting*)malloc(n * sizeof(struct Meeting));

    // ����ڷκ��� ȸ�� ���� �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        printf("ȸ�� %d�� ���� �ð��� �Է��ϼ���: ", i + 1);
        scanf_s("%d", &meetings[i].start);

        printf("ȸ�� %d�� ������ �ð��� �Է��ϼ���: ", i + 1);
        scanf_s("%d", &meetings[i].end);

        meetings[i].id = i + 1;  // ȸ�� ��ȣ �ο�
    }

    printMaxMeetings(meetings, n);

    free(meetings);  // �������� �Ҵ��� �޸� ����

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main �Լ� ȣ��
        }
    }
}
