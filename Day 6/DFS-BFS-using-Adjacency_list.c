#include <stdio.h>
#include <stdlib.h>
#define m 20

typedef struct node
{
    char data;
    struct node *next;
}node;

node* graph[m];
node *head = NULL, *tail = NULL;

int visited[m], stack[m], visit[m], q[m];

int top = -1, rear = -1, front = -1;

node *makeList(int n, char x)
{
    node *newnode = (node *)malloc(sizeof (node));
    newnode -> next = NULL;
    newnode -> data = x;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail -> next = newnode;
        tail = newnode;
    }
    return head;
}

void printGraph (int n)
{
    for (int i = 0; i < n; i++)
    {
        node *temp = NULL;
        temp = graph[i];
        printf("\n The adjacent vertices of %c is :: ",i+65);
        while (temp != NULL)
        {
            printf("%c\t", temp->data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void push (char x)
{
    if (top == m-1)
    {
        printf("Stack Overflowing!!!");
    }
    else{
        top ++;
        stack [top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\n Stack Underflow!!!");
    }
    else
    {
        top --;
    }
}

void DFS(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int v = 0;
    char u;
    push (v + 65);
    visited[v] = 1;
    printf("\n The DFS traversal of the graph is :: \n");
    while (top != -1)
    {
        u = stack[top];
        pop();
        printf("%c \t", u);
        node *temp = graph[u-65];
        while (temp != NULL)
        {
           if (visited[(temp -> data)-65] == 0)
           {
                push (temp -> data);
                visited[(temp -> data - 65)] = 1;
           }
            temp = temp -> next;
        }
    }
}

void enque(char x)
{
    if (rear == m-1)
    {
        printf("\n Queue Overflow!!!");
    }
    else if (rear == -1 && front == -1)
    {
        rear ++;
        front ++;
        q[rear] = x;
    }
    else
    {
        rear ++;
        q[rear] = x;
    }
}

void deque ()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue Underflow!!! \n");
    }
    else if (front == rear)
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
    int v = 0;
    enque (v + 65);
    visit[v] = 1;
    char u;
    printf("\n The BFS traversal of the following graph is :: \n");
    while ((rear != -1 && front != -1) || front < rear)
    {
        u = q[front];
        deque();
        printf("%c\t", u);
        node *t = graph[u-65];
        while (t != NULL)
        {
            if (visit[(t -> data) - 65] == 0)
            {
                enque (t -> data);
                visit[(t -> data) - 65] = 1;
            }
            t = t -> next;
        }
    }
}

int main()
{
    FILE *fp = fopen ("abc.txt", "r");
    if (fp == NULL)
    {
        printf ("\n Error opening\n");
    }
    int n, x;
    fscanf (fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = NULL;
        for (int j = 0; j < n; j ++)
        {
            fscanf (fp, "%d", &x);
            if (x == 1)
            {
                graph[i] = makeList (n, j+65);
            }
        }
    }
    printGraph(n);
    DFS (n);
    BFS (n);
    return 0;
}