#include <stdio.h>
#include <stdlib.h>
#define m 20
int g[m][m];
int n, size, s;
float  weight = 0.0;
int parent[m];
typedef struct graph
{
    char v1;
    char v2;
    float w;
}graph;
graph g1[m], soln[m];
void print(int arr[m][m])
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void Graph ()
{
    int k =0;
    for (int i = 0; i < n; i ++)
    {
        for (int j = i; j < n; j ++)
        {
            if (g[i][j] > 0){
                g1[k].v1 = i + 65;
                g1[k].v2 = j + 65;
                g1[k].w = g[i][j];
                k ++;
            }
        }
    }
    size = k;
}
void printGraph (graph a[m], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("\nWeight :: %.2f     %c <--> %c", a[i].w, a[i].v1, a[i].v2);
    }
}
void makeSet()
{
    for (int i = 0; i < m; i ++)
    {
        parent[i] = -1;
    }
}
int simpleFind (int i)
{
    while (parent[i] >= 0)
    {
        i = parent[i];
    }
    return i;
}
void weighted_Union (int i, int j){
    int count = parent[i] + parent[j];
    if (parent[i] < parent[j])
    {
        parent[j] = i;
        parent[i] = count;
    }
    else
    {
        parent[i] = j;
        parent[j] = count;
    }
}
void kruskal ()
{
    makeSet();
    int k = 0;
    s = 0;
    for (int i = 0; i < size; i ++){
        if (simpleFind(g1[i].v1 -65) != simpleFind(g1[i].v2 -65))
        {
            soln[k].v1 = g1[i].v1;
            soln[k].v2 = g1[i].v2;
            soln[k].w = g1[i].w;
            weight += g1[i].w;
            s ++;
            k ++;
            weighted_Union(g1[i].v1-65, g1[i].v2-65);
        }
    }
}
int comparator(const void *p, const void *q) 
{
    int l = ((struct  graph*)p)->w;
    int r = ((struct graph *)q)->w; 
    return (l - r);
}
int main()
{
    FILE *fp = fopen ("abc.txt", "r");
    if (fp == NULL)
    {
        printf("\n Cannot open file");
    }
    int x;
    fscanf (fp, "%d", &n);
  
    for(int i=0; i<n; i++)
    {
        for(int j=0; j< n; j++)
        {
            fscanf (fp, "%d", &x);
            g[i][j] = x;
        }
    }
    printf("\n The total number of vertices :: %d\n",n);
    printf("The graph is :: \n");
    print(g);
    Graph ();
    printf("\n************BEFORE SORTING**************");
    printGraph (g1, size);
    qsort(g1, size, sizeof(struct graph), comparator);
    printf("\n************AFTER SORTING***************");
    printGraph (g1, size);
    kruskal ();
    printf("\n************The MST Is******************");
    printf("\n The minimum weight is :: %.2f", weight);
    printGraph (soln, s);
}