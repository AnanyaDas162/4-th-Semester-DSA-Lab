#include <bits/stdc++.h>

using namespace std;

int n, i, j, y, var; 
int p[10], w[10];
int x[100][100];

void print(int arr[10]){
   for (i = 0; i < n; i ++){
        cout << arr[i] << "\t";
   }
   cout << endl;
}

void input(){
   ifstream in ("ks.txt");
   in >> n;
   cout << "Number of items :: " << n << endl; 
   for (i = 1; i <= n; i ++){
        in >> var;
        p[i] = var;
   }
   for (i = 1; i <= n; i ++){
        in >> var;
        w[i] = var;
   }
   in >> y;
   cout << "Knap-Sack Capacity = " << y << endl;
}

int knapSack (){
   for (i = 0; i <=y; i ++){
       x[i][0] = 0;
   }
    for (i = 0; i < n+1; i ++){
       x[0][i] = 0;
   }
   for (i = 1; i < n+1; i ++){
       for (j = 1; j < y+1; j ++){
           if(w[i] <= j){
               x[i][j] = max(p[i] + x[i-1][j-w[i]], x[i-1][j]);
           }
           else{
               x[i][j] = x[i-1][j];
           }
       }
   }
   cout << endl;
   return x[n][y];
}
int main(){
   input();
   print(p);
   print(w);
   int d = knapSack();
   cout << "Knapsack profit = " << d;
   cout << endl;
   for (i = 0; i < n+1; i ++){
       for (j = 0; j < y+1; j ++){
           cout << x[i][j] << "\t";
       }
       cout << endl;
   }
}
