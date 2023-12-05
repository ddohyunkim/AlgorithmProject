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


// 두 회의를 비교하여 정렬하기 위한 비교 함수
int compareMeetings(const void* a, const void* b) {
    return ((struct Meeting*)a)->end - ((struct Meeting*)b)->end;
}

// 그리디 알고리즘을 사용하여 최대로 선택할 수 있는 회의를 출력하는 함수
void printMaxMeetings(struct Meeting meetings[], int n) {
    // 회의를 끝나는 시간을 기준으로 정렬
    qsort(meetings, n, sizeof(struct Meeting), compareMeetings);

    printf("최대로 선택할 수 있는 회의:\n");

    // 첫 번째 회의는 항상 선택
    int i = 0;
    printf("회의 %d: 시작 시간 = %d, 끝나는 시간 = %d\n", meetings[i].id, meetings[i].start, meetings[i].end);

    // 선택한 회의의 끝나는 시간보다 뒤에 시작하는 회의를 선택
    for (int j = 1; j < n; j++) {
        if (meetings[j].start >= meetings[i].end) {
            printf("회의 %d: 시작 시간 = %d, 끝나는 시간 = %d\n", meetings[j].id, meetings[j].start, meetings[j].end);
            i = j;
        }
    }
}

void myGreed() {
    int n;
    setColor(WHITE);

    printf("회의의 개수를 입력하세요: ");
    scanf_s("%d", &n);

    struct Meeting* meetings = (struct Meeting*)malloc(n * sizeof(struct Meeting));

    // 사용자로부터 회의 정보 입력 받기
    for (int i = 0; i < n; i++) {
        printf("회의 %d의 시작 시간을 입력하세요: ", i + 1);
        scanf_s("%d", &meetings[i].start);

        printf("회의 %d의 끝나는 시간을 입력하세요: ", i + 1);
        scanf_s("%d", &meetings[i].end);

        meetings[i].id = i + 1;  // 회의 번호 부여
    }

    printMaxMeetings(meetings, n);

    free(meetings);  // 동적으로 할당한 메모리 해제

    getchar();
    while (1) {
        if (keyControl() == SUBMIT) {
            main(); // main 함수 호출
        }
    }
}
