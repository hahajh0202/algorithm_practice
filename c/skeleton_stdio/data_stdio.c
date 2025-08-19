#include <stdio.h>
#include <string.h>
#define MAX_CMD_NUMBER  10000
#define MAX_DATA_NUMBER 10000

/* Data Structure define */
int queue[MAX_DATA_NUMBER];
int frnt = 0;
int rear = 0;

/* stack, queue 데이터 구조 관련 함수 정의 */
void push(int input_num);
void pop(void);
void size(void);
void empty(void);
void front(void);
void back(void);


int main(){
    int cmd_number;

    printf("명령어 개수: ");
    scanf("%d", &cmd_number);   /* scanf는 \n 앞까지만 변수를 넣음. */
    getchar();                  /* 버퍼에 남은 \n을 삭제(반환), stdin 버퍼에서 하나의 문자만 읽음. */

    for (int i = 0; i < cmd_number; i++)
    {
        char cmd[MAX_CMD_NUMBER];
        char sscanf_str[MAX_CMD_NUMBER];
        int sscanf_int;
        int sscanf_result;

        printf("명령어를 입력: ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        sscanf_result = sscanf(cmd, "%s %d", sscanf_str, &sscanf_int);
        if (sscanf_result == 2 && strcmp(sscanf_str, "push") == 0)
        {
            /* push 실행 */
            push(sscanf_int);
        }
        else if (sscanf_result == 1 && strcmp(sscanf_str, "pop") == 0)
        {
            pop();
        }
        else if (sscanf_result == 1 && strcmp(sscanf_str, "size") == 0)
        {
            size();
        }
        else if (sscanf_result == 1 && strcmp(sscanf_str, "empty") == 0)
        {
            empty();
        }
        else if (sscanf_result == 1 && strcmp(sscanf_str, "front") == 0)
        {
            front();
        }
        else if (sscanf_result == 1 && strcmp(sscanf_str, "back") == 0)
        {
            back();
        }
        else
        {
            printf("유효한 명령어를 입력해주세요.\n");
        }
    }

    return 0;
}

void push(int input_num){
    queue[++rear - 1] = input_num;
}

void pop(void){
    if (frnt == rear){
        printf("-1\n");
    }
    else {
        printf("%d\n", queue[frnt++]);
    }
}

void size(void){
    if (frnt == rear){
        printf("-1\n");
    }
    else {
        printf("%d\n", rear - frnt);
    }
}

void empty(void){
    if (frnt == rear) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

void front(void){
    if (frnt == rear){
        printf("-1\n");
    }
    else {
        printf("%d\n", queue[frnt]);
    }
}

void back(void){
    if (frnt == rear){
        printf("-1\n");
    }
    else {
        printf("%d\n", queue[rear - 1]);
    }
}