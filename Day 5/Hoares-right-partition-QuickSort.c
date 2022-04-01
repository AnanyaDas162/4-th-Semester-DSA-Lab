#include <stdio.h>
#define m 20
int arr[m];
int Hoare_right_partition(int arr[m], int low, int high)
{
    int i = low - 1;
    int j = high, temp;
    int pivot = arr[high];
    while (i < j)
    {
        do{
            i ++;
        }while(arr[i] < pivot);
        do{
            j --;
        }while(j >= 0 && arr[j] > pivot);
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i];
    arr[i] = arr[high];        
    arr[high] = temp;
    return i;
}
void QuickSort(int arr[m], int low, int high)
{
    int j;
    if (low < high)
    {
        j = Hoare_right_partition(arr, low, high);
        QuickSort(arr, low, j-1);
        QuickSort(arr, j+1, high);
    }
}
int main()
{
    int n;
    printf("\n Enter the number of elements :: ");
    scanf("%d", &n);
    printf("\n Enter the array elements :: ");
    for (int i = 0 ; i < n; i ++)
    {
        scanf("%d", &arr[i]);
    }
    int low = 0;
    int high = n-1;
    QuickSort(arr, low, high);
    printf("\n After sorting the array :: \n");
    for (int i = 0; i < n; i ++)
    {
        printf("\t %d", arr[i]);
    }
}
