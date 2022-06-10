#include <stdio.h>
#include <limits.h>
#define q 10
int p[q];
int num, i, j, k, len, cost;//number of matrices
int m[q][q], s[q][q];

void POP(int s[q][q], int i, int j){
    if (i == j){
        printf("A%d", i-1);
    }
    else{
        printf("(");
        POP(s, i, s[i][j]);
        POP(s, s[i][j]+1, j);
        printf(")");
    }
}

void matrix_chain(){
    int n = num + 1;
    for (i = 1; i <= n; i ++){
        m[i][i] = 0;
    }
    for (len = 2; len <= n; len++){
        for (i = 1; i <= n-len+1; i++){
            j = i+len-1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j-1; k++){
                cost = m[i][k] + m[1+k][j] + (p[i-1] * p[j] * p[k]);
                if (m[i][j] > cost){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    POP(s,i, j);
}

int main(){
    printf("\n Enter the number of matrices :: ");
    scanf("%d",&num);
    printf("\n Enter the orders of the matrices ::\n");
    for (int i = 1; i <= num+1; i ++){
        scanf("%d",&p[i]);
    }
    matrix_chain();
    printf("\nThe cost is %d\n",m[2][num+1]);
    /*for (int i = 1; i <= num+1; i ++){
        for (j = 1; j <= num+1; j ++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
     for (int i = 1; i <= num+1; i ++){
        for (j = 1; j <= num+1; j ++){
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }*/
}