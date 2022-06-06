#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#define m 40
int gr[m][m], dist[m], parent[m];
int n, k = 0;
char u;

typedef struct graph{
    char v1;
    char v2;
    int w;
}graph;

graph g[m];

void initialize(){
    for(int i=0;i<m;i++){
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
}
void print_Distance(){
    for(int i=0;i<n;i++){
        printf("\n%c  <-->  %c  -->  %d\n", u, i+65, dist[i]);
    }
}
bool Bellman_Ford(){
    initialize();
    printf("\n Enter the starting vertex :: \n");
    fflush(stdin);
    scanf("%c", &u);
    dist[u-65] = 0;
    int it = 0;
    while(it < n-1){
        for (int i=0;i<=k;i++){
            if (dist[g[i].v1 - 65] + g[i].w < dist[g[i].v2 - 65]){
                dist[g[i].v2 - 65] = dist[g[i].v1 - 65] + g[i].w;
                parent[g[i].v2 - 65] = g[i].v1 - 65;
                //printf("%d\t",  dist[g[i].v2 - 65] );
            }
        }
        it ++;
    }
     for (int i=0;i<=k;i++){
        if (dist[g[i].v1 - 65] + g[i].w < dist[g[i].v2 - 65]){
            //printf("Hii");
            return false;
        }
    }
    return true;
}
void print (int arr[m][m], int x){
    for (int i = 0; i < x; i ++){
        for (int j = 0; j < x; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void print_edges (){
    /*for (int i = 0; i < k; i ++){
        printf("\n%c  <-->  %c  --->  %d\n",g[i].v1, g[i].v2, g[i].w);
    }*/
    if (Bellman_Ford()){
        print_Distance();
    }
    else{
        printf("\n Negative edge cycle is present\n");
    }
}
void input(char str[m]){
    int x;
    FILE *fp = fopen (str, "r");
    if (fp == NULL){
        printf("Cannot open file\n");
    }
    fscanf (fp, "%d", &n);
    printf("\n The number of vertices :: %d\n",n);
    k = 0;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++){
            fscanf (fp, "%d", &x);
            gr[i][j] = x;
            if (x != 0){
                g[k].v1 = i+65;
                g[k].v2 = j+65;
                g[k].w = x;
                k ++;
            }
        }
    }
    print(gr, n);
    print_edges ();
}
int main(){
    char str[m] = "negative-edge-graph-without-any-cycle.txt";
    char s[m] = "abc.txt";
    char st[m] = "negative-edge-cycle.txt";
    input(str);
    input(s);
    input(st);
    return 0;
}
