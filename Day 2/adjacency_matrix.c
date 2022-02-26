#include <stdio.h>
/*Write a program in C or C++ to read a graph from file and to store the graph in
adjacency matrix. Implement the following operations.
1. Find the number of edges of the graph.
2. Find the total degree of the graph.
3. Display the adjacent of a given vertex.
4. Display the graph.*/
int main()
{
   FILE *fp;
   fp = fopen("abc.txt","r");
   if (fp == NULL)
   {
      printf("\n Cannot open the file");
   }
   int n;
   fscanf(fp, "%d", &n);
   int arr[n][n]; 
   int edges = 0, i, j;
   for (i = 0; i < n; i ++)
   {
       for (j = 0; j < n; j ++)
       {
            fscanf(fp, "%d", &arr[i][j]);
            printf("%6d",arr[i][j]);
            if (arr[i][j] == 1)
            {
                 edges++;
            }
       }
       printf("\n");
   }
   edges = edges / 2;
   printf("\n The number of edges of the graph is %d", edges);
   printf("\n The sum of the degrees of the vertices is %d", 2*edges);
   printf("\n The adjacent edges are ::");
   for (i = 0; i < n; i ++)
   {
       printf("%c",i+65);
       printf(" is connected with ");
       for(j = 0; j < n; j ++)
       {
          
           if (arr[i][j] == 1)
           {
                printf(" %c ",j+65);
           } 
       }
       printf("\n");
   }
   return 0;
}
