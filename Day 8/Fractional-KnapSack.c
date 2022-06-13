#include <stdio.h>
#define m 20
typedef struct knapsack
{
     float p;//profit
     float w;//weight
     int it;//item number
     float p_w;//profit per weight
}ks;
ks arr[m];
//int pw[m];
int n, max;
float x[m];
float profit = 0.0;
void input ()
{
   int i;
   for (i = 0; i < n; i ++)
   {
        printf("\n Enter the profit :: ");
        scanf("%f", &arr[i].p);
        printf("\n Enter the weight ::  ");
        scanf("%f", &arr[i].w);
        arr[i].p_w = (arr[i].p) / (arr[i].w);
   }
}
void print ()
{
    int j;
    for (j = 0; j < n; j ++)
   {
       printf("\nprofit --> %f\t weight --> %f\t profit per weight --> %f\t\n", arr[j].p, arr[j].w,arr[j].p_w);
   }
}
void interchange (int x, int y)
{
    ks temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    /*s[y] = arr[x].w;
    s[x] = arr[y].w;
    pr[y] = arr[x].p;
    pr[x] = arr[y].p;*/
}
int hoare_partition (int low, int high)
{
    int i = low;
    int j = high + 1;
    float pivot = arr[low].p_w;
    while (i < j)
    {
        do
        {
              i = i + 1;
        }while(i <= high && arr[i].p_w > pivot);
        do
        {
              j = j - 1;
        }while(arr[j].p_w < pivot);
        if (i < j)
        {
              interchange(i, j);
        }
    }
    interchange (low, j);
    return j;
}
void quickSort(int low, int high)
{
   if (low < high)
   {
       int j = hoare_partition(low, high);
       quickSort (low, j-1);
       quickSort (j+1, high);
   }
}
void knapSack(int max)
{
    int i;
    for (i = 0; i < n; i ++)
   {
         if (arr[i].w <= max)
         {
              x[i] = 1.0;
              max = max - arr[i].w;
              profit = profit + arr[i].p;
         }
         else
         {
              break;
         }
   }
   if (i < n)
   {
         x[i] = (float)max / arr[i].w;
         profit = profit + (x[i] * arr[i].p);
   }
}
int main()
{
   printf("\n Enter the number of items :: \n");
   scanf("%d", &n);
   input ();
   int low = 0, high = n-1, j;
   quickSort(low, high);
   printf("\n *****After Sorting******\n");
   printf("\n The profit per weight array is :: ");
   print ();
   int i;
   for (i = 0; i < n; i ++)
   {
       x[i] = 0.0;
   }
   printf("\n Enter te maximum capacity :: \n");
   scanf("%d", &max);
   knapSack(max);
   printf("\n The x array is \n");
   for (j = 0; j < n; j ++)
   {
       printf("%f\t", x[j]);
   }
   printf("\n The profit is %f", profit);
   return 0;
}
