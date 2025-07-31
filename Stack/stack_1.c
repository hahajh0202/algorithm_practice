#include <stdio.h>
#include <string.h>
#define COMMAND_MAX_LENGTH 10
#define STACK_SIZE 10

int stack_array[STACK_SIZE];
int top_index = -1;
void push(int num);
void pop(void);
void top(void);
void size(void);
void empty(void);

int main(){
    int cmd_num;

    scanf("%d", &cmd_num);
    getchar();  /* 개행 문자 제거 */


    for(int i = 0; i < cmd_num; i++)
    {
        char cmd[COMMAND_MAX_LENGTH];

        fgets(cmd, COMMAND_MAX_LENGTH, stdin);  /* 공백 포함 문자열 입력 받기 위함 (ex. push 4) */
        cmd[strcspn(cmd, "\n")] = '\0';         /* fgets로 들어온 \n(개행문자) 찾아서(인덱싱, index = strcspn(cmd, "\n")) 제거 */

        if(strncmp(cmd, "push", 4) == 0)        /* cmd의 앞에서 4글자만 push와 같은지 비교 */
        {
            int input_stack;
            sscanf(cmd + 5, "%d", &input_stack);/* "push " 다음의 숫자 부분 추출 (+5는 "push " 포함 5글자 넘기는 의미)*/
            push(input_stack);
        }
        else if(strcmp(cmd, "pop") == 0)
        {
            cmd[strcspn(cmd, "\n")] = ' ';
            pop();
        }
        else if(strcmp(cmd, "top") == 0)
        {
            top();
        }
        else if(strcmp(cmd, "size") == 0)
        {
            size();
        }
        else if(strcmp(cmd, "empty") == 0)
        {
            empty();
        }
        else
        {
            printf("알 수 없는 명령어 입니다. \n");
        }
    }

    return 0;
}

void push(int num){
    if (top_index >= STACK_SIZE - 1)
    {
        printf("스택 오버플로우\n");
    }
    else
    {
        stack_array[++top_index] = num;
    }
}

void pop(void){
    if (top_index < 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", stack_array[top_index--]);
    }
}

void top(void){
    if (top_index < 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", stack_array[top_index]);
    }
}

void size(void){
    printf("%d\n", top_index + 1);
}

void empty(void){
    int isEmpty = (top_index == -1) ? 1 : 0;
    printf("%d\n", isEmpty);
}