// Heap Sort
#include <stdio.h>
#define m 20
int arr[m];
void heap_adjust (int i, int n)
{
    int j = 2 * i;
    int key = arr[i];
    while (j <= n)
    {
        if (j < n && arr[j + 1] > arr[j])
        {
            j = j + 1;
        }
        if (arr[j] <= key)
        {
            break;
        }
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j/2] = key;
}
void makeHeap (int n)
{
    for (int i = n/2; i >= 0; i --)
    {
        heap_adjust(i, n);
    }
}
void heapSort (int n)
{
    makeHeap(n);
    int temp;
    for (int i = n; i >= 0; i --)
    {
        //interchange
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heap_adjust (0, i-1);
    }
}
int main()
{
    int n;
    printf("\n Enter the number of elements in the array :: ");
    scanf("%d", &n);
    printf("\n Enter the array elements :: \n");
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &arr[i]);
    }
    heapSort(n-1);
    for (int i = 0; i < n;i ++)
    {
        printf("%d \t", arr[i]);
    }
}
