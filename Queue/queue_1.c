#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10000
#define MAX_CMD_LENGTH 20

int queue[MAX_QUEUE_SIZE];
int frnt = 0;
int rear = 0;   
/* 큐가 비었는지 확인할 땐 front == rear */
/* 큐의 크기는 rear - front */

void push(int input_int);
void pop(void);
void size(void);
void empty(void);
void front(void);
void back(void);


int main(){
    int cmd_number;
    char cmd[MAX_CMD_LENGTH] = {0, };

    scanf("%d", &cmd_number);
    getchar();


    for(int i = 0; i < cmd_number; i++)
    {
        char sscanf_str[MAX_CMD_LENGTH] = {0,};
        int sscanf_int = 0;

        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        int parsed = sscanf(cmd, "%s %d", sscanf_str, &sscanf_int);

        if(parsed == 2 && strcmp(sscanf_str, "push") == 0)
        {
            push(sscanf_int);
        }
        else if(strcmp(sscanf_str, "pop") == 0)
        {
            pop();
        }
        else if(strcmp(sscanf_str, "size") == 0)
        {
            size();
        }
        else if(strcmp(sscanf_str, "empty") == 0)
        {
            empty();
        }
        else if(strcmp(sscanf_str, "front") == 0)
        {
            front();
        }
        else if(strcmp(sscanf_str, "back") == 0)
        {
            back();
        }
        else
        {
            /* Do Nothing */
        }
    }


    return 0;
}

void push(int input_int)
{
    queue[++rear-1] = input_int;
}

void pop(void)
{
    if (rear == frnt){
        printf("-1\n");
    }
    else{
        printf("%d\n", queue[frnt++]);
    }
}

void size(void){
    printf("%d\n", rear - frnt);
}

void empty(void){
    if (rear == frnt){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}

void front(void){
    if (rear == frnt){
        printf("-1\n");
    }
    else{
        printf("%d\n", queue[frnt]);
    }
}

void back(void){
    if (rear == frnt){
        printf("-1\n");
    }
    else{
        printf("%d\n", queue[rear - 1]);
    }
}