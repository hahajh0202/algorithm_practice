#include <stdio.h>
#include <string.h>
#define MAX_CMD_LENGTH  20
#define MAX_DEQUE_SIZE  200

int deque[MAX_DEQUE_SIZE];
int frnt = MAX_DEQUE_SIZE / 2;
int rear = MAX_DEQUE_SIZE / 2;

void push_front(int input_num);
void push_back(int input_num);
void pop_front(void);
void pop_back(void);
void size(void);
void empty(void);
void front(void);
void back(void);


int main(){
    int cmd_number;

    scanf("%d", &cmd_number);
    getchar();

    for (int i = 0; i < cmd_number; i++)
    {
        char cmd[MAX_CMD_LENGTH];
        int sscanf_result;
        char sscanf_str[MAX_CMD_LENGTH];
        int sscanf_int;

        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        sscanf_result = sscanf(cmd, "%s %d", sscanf_str, &sscanf_int);

        if (sscanf_result == 2 && strcmp(sscanf_str, "push_front") == 0)
        {
            push_front(sscanf_int);
        }
        else if (sscanf_result == 2 && strcmp(sscanf_str, "push_back") == 0)
        {
            push_back(sscanf_int);
        }
        else if (sscanf_result == 1)
        {
            if (strcmp(sscanf_str, "pop_front") == 0)
            {
                pop_front();
            }
            else if (strcmp(sscanf_str, "pop_back") == 0)
            {
                pop_back();
            }
            else if (strcmp(sscanf_str, "size") == 0)
            {
                size();
            }
            else if (strcmp(sscanf_str, "empty") == 0)
            {
                empty();
            }
            else if (strcmp(sscanf_str, "front") == 0)
            {
                front();
            }
            else if (strcmp(sscanf_str, "back") == 0)
            {
                back();
            }
            else {
                /* Do Nothing */
            }
        }
        else {
            /* Do Nothing */
        }
    }

    return 0;
}

void push_front(int input_num){
    deque[--frnt] = input_num;
}

void push_back(int input_num){
    deque[rear++] = input_num;
}

void pop_front(void){
    if (rear == frnt){
        printf("-1\n");
    }
    else {
        printf("%d\n", deque[frnt++]);
    }
}

void pop_back(void){
    if (rear == frnt){
        printf("-1\n");
    }
    else {
        printf("%d\n", deque[--rear]);
    }
}

void size(void){
    printf("%d\n", rear - frnt);
}

void empty(void){
    printf("%d\n", (rear == frnt) ? 1 : 0);
}

void front(void){
    if (rear == frnt){
        printf("-1\n");
    }
    else {
        printf("%d\n", deque[frnt]);
    }
}

void back(void){
    if (rear == frnt){
        printf("-1\n");
    }
    else {
        printf("%d\n", deque[rear - 1]);
    }
}