#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define m 10
int x[m];
void chess_board(int n){
    for (int i = 1; i < n+1; i ++){
        for (int j = 1; j < n+1; j++){
            if (x[i] == j){
                printf("Q\t");
            }
            else{
                printf("--\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void print(int n){
    for (int i = 1; i < n+1; i ++){
        printf("%d\t", x[i]);
    }
    printf("\n");
    chess_board(n);
}
bool place (int k, int i){
    for (int j = 1; j <= k-1; j ++){
        if (x[j] == i || abs(x[j] - i)==abs(j-k)){
            return false;
        }
    }
    return true;
}
void n_queen(int k, int n){
    for (int i = 1; i <= n; i ++){
        if (place(k,i)){
            x[k] = i;
            if (k == n){
                print(n);
            }
            else{
                n_queen(k+1, n);
            }
        }
    }
}
int main(){
    int n;
    printf("\n Enter the order of chess-board :: \n");
    scanf("%d", &n);
    n_queen(1, n);
}