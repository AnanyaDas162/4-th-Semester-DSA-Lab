#include <bits/stdc++.h>
#include <fstream>
#define m 10
using namespace std;
int n, i, j;
int g[m][m];
int parent[m], dist[m], mstSet[m];

typedef pair < int,pair < char,char > > p;
priority_queue<p, vector<p>, greater<p> > pq;

void initialize (){
   for (i = 0; i < n; i ++){
       parent[i] = -1;
       dist[i] = INT_MAX;
       mstSet[i] = false;
   }
}

void dijkstra (){
   initialize();
   cout << "Enter the starting vertex :: " << endl;
   char y;
   cin >> y;
   dist[y-65] = 0;
   pq.push(make_pair(0,make_pair(y, y)));  
   while (!pq.empty()){
        int u = pq.top().second.second;
        if (!mstSet[u-65]){
            cout << "Shortest Path Cost :: "<< pq.top().first << " \t " << pq.top().second.first << " <--> " << pq.top().second.second << endl;
        }
        mstSet[u-65] = true;
        pq.pop();
        for (j = 0; j < n; j ++){
             if (g[u-65][j] > 0){
                 if (mstSet[j] == false && dist[u-65]+g[u-65][j] < dist[j]){
                      dist[j] = dist[u-65] + g[u-65][j];
                      pq.push(make_pair(dist[j], make_pair(y, j+65)));
                      parent[j] = u;
                 }
             }
        }
   }
}

void print (int arr[m][m]){
   for (i = 0; i < n; i ++){
       for (j = 0; j < n; j ++){
            cout << arr[i][j] << "\t";
       }
       cout << endl;
   }
}

void input(){
   int x;
   ifstream in ("abc.txt");
   in >> n;
   cout << "The number of vertices = " << n << endl;
   for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
             in >> x;
             g[i][j] = x;
        }
   }
}

int main(){
   input();
   print(g);
   dijkstra();
   return 0;
}