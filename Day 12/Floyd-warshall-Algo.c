#include <stdio.h>
#include <limits.h>
#define macro 10

int n, i, j, k, x;
int g[macro][macro], d[macro][macro], p[macro][macro];

void input (){
    FILE *fp;
    fp = fopen ("abc.txt", "r");
    if (fp == NULL){
        printf("\n Can not open file\n");
        return;
    }
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j ++){
            fscanf(fp, "%d", &x);
            g[i][j] = x;
        }
    }
}

void print_matrix(int arr[macro][macro]){
    for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall(){
    for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
            if (i == j){
                d[i][j] = 0;
            }
            else if (g[i][j] == 0){
                d[i][j] = INT_MAX;
            }
            else{
                d[i][j] = g[i][j];
            }
            if (i == j || d[i][j] == INT_MAX){
                p[i][j] = -1;
            }
            else{
                p[i][j] = i;
            }
        }
    }
    /*print_matrix(d);
    print_matrix(p);*/
    for (k = 0; k < n; k ++){
        for (i = 0; i < n; i ++){
            for (j = 0; j < n; j ++){
                if ((d[i][k] + d[k][j] < d[i][j]) && d[i][k] != INT_MAX && d[k][j] != INT_MAX){
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

void APSP(int i, int j){
    if (i == j){
        printf("%d\t", i+1);
    }
    else if(p[i][j] == -1){
        printf("\nThere is no path between %d and %d", i, j);
    }
    else{
        APSP(i, p[i][j]);
        printf("%d\t", j+1);
    }
}

int main(){
    input ();
    print_matrix(g);
    floyd_warshall();
    printf("\n The distances are:: \n");
    print_matrix(d);
    printf("\n The parent matrix is :: \n");
    print_matrix(p);
    for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
            printf("\n Path between %d and %d ::\n",i+1, j+1);
            APSP(i,j);
        }
    }
}