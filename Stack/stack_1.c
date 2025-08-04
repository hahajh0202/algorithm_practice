#include <stdio.h>
#include <string.h>

#define COMMAND_MAX_LENGTH 20
#define STACK_SIZE 10000

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
    getchar();  // 개행 문자 제거

    for(int i = 0; i < cmd_num; i++)
    {
        char cmd[COMMAND_MAX_LENGTH];
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';  // 개행 문자 제거

        if (strncmp(cmd, "push", 4) == 0)
        {
            int x;
            sscanf(cmd + 5, "%d", &x);  // "push " 다음 숫자 추출
            push(x);
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            pop();
        }
        else if (strcmp(cmd, "top") == 0)
        {
            top();
        }
        else if (strcmp(cmd, "size") == 0)
        {
            size();
        }
        else if (strcmp(cmd, "empty") == 0)
        {
            empty();
        }
        // "알 수 없는 명령어입니다"는 생략해야 함
    }

    return 0;
}

void push(int num){
    if (top_index < STACK_SIZE - 1)
        stack_array[++top_index] = num;
}

void pop(void){
    if (top_index < 0)
        printf("-1\n");
    else
        printf("%d\n", stack_array[top_index--]);
}

void top(void){
    if (top_index < 0)
        printf("-1\n");
    else
        printf("%d\n", stack_array[top_index]);
}

void size(void){
    printf("%d\n", top_index + 1);
}

void empty(void){
    printf("%d\n", top_index == -1 ? 1 : 0);
}
