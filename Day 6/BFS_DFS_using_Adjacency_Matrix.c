#include <stdio.h>
//#include <./stackLib.c>
#define m 20
int graph[m][m];
int visited[m], visit[m];
char stack[m], queue[m];
int top = -1, rear = -1, front = -1;
void enque(int n, char x)
{
    if (rear == -1 && front == -1)
    {
        rear ++;
        front ++;
        queue[rear] = x;
    }
    else if (rear == n-1)
    {
        printf("\n The queue is overflowing !!! \n");
    }
    else
    {
        rear ++;
        queue[rear] = x;
    }
}
void deque(int n)
{
    if (rear == -1 && front == -1)
    {
        printf("\n The queue is underflowing!!! \n");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front ++;
    }
}
void BFS (int n)
{
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }
    int v = 0;
    char u;
    enque (n, v+65);
    visit[v] = 1;
    printf("\n The BFS traversal of the graph is :: \n");
    while ((rear != -1 && front != -1) || front < rear)
    {
        u = queue[front];
        deque(n);
        printf("%c\t", u);
        for (int i = 0; i < n; i ++)
        {
            if (graph[u-65][i] == 1)
            {
                if (visit[i] == 0)
                {
                    enque (n, i+65);
                    visit[i] = 1;
                }
            }
        }
    }
}
void push (int v)
{
    if (top == m-1)
    {
        printf("The stack is overflowing ");
    }
    else
    {
        top ++ ;
        stack[top] = v;
    }
}
void pop ()
{
    if (top == -1)
    {
        printf("\n Underflow!!!\n");
    }
    else
    {
        top --;
    }
}
void DFS(int n)
{
    char u;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int v = 0;
    push (v + 65);
    visited[v] = 1;
    printf("\n The DFS traversal of the following graph is :: \n");
    while (top != -1)
    {
        u = stack[top];
        pop();
        printf("%c \t", u);
        for (int i = 0; i < n; i ++)
        {
            if (graph[u-65][i] == 1)
            {
                if (visited[i] == 0)
                {
                    push(i + 65);
                    visited[i] = 1;
                }
            }
        }
    }
}
void print(int n)
{
    printf("\n The graph is :: \n");
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    FILE *fp = fopen("abc.txt", "r");
    if (fp == NULL)
    {
        printf("\n Error opening \n");
    }
    int n, x;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    print(n);
    DFS (n);
    BFS (n);
    return 0;
}
