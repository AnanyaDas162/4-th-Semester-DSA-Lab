#include <stdio.h>
#include <stdlib.h>
/*Write a program in C or C++ to read a graph from file and store it in adjacency
list. Then implement the following operations.
1. Find the number of edges of the graph.
2. Find the total degree of the graph.
3. Display the adjacent of a given vertex.
4. Display the graph.
*/
typedef struct node {
    int data;
    struct node *next;
}node;
node *arr[30];
void print_graph(int n, int matrix[n][n])
{
    printf("\n ******THe Graph is Printing ******\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void adjacency_list(int n, int matrix[n][n])
{
    node*newnode = NULL;
    node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        head = NULL, temp = NULL;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                newnode = (node *) malloc (sizeof (node));
                newnode->data = j+65;
                newnode-> next = NULL;
                if (head == NULL)
                {
                    head = newnode;
                    temp = newnode;
                }
                else
                {
                    temp -> next = newnode;
                    temp = newnode;
                }
            }
        }
        arr[i]=head;
    }
}
void adjacent_vertices(int n)
{
    int count_edges = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%c is connected with :  ", i+65);
        node *temp = arr[i];
        while(temp != NULL)
        {
            printf("%c  ",temp-> data);
            count_edges ++;
            temp = temp -> next;
        }
        printf("\n");
    }
    count_edges /= 2;
    printf("\n The number of edges in the graph is %d",count_edges);
    printf("\n The total degree of the graph is %d",count_edges*2);
}
int main()
{
    FILE *fp = fopen("abc.txt", "r");
    int n, x;
    if (fp == NULL)
    {
        printf("File can not be opened.");
    }
    fscanf(fp, "%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j ++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    print_graph(n, matrix);
    adjacency_list(n, matrix);
    adjacent_vertices(n);
    fclose(fp);
    return 0;
}