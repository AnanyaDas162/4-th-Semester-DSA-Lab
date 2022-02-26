#include <bits/stdc++.h>
using namespace std;
void merge(int n, int arr[100], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i ++;
        }
        else
        {
            b[k] = arr[j];
            j ++;
        }
        k ++;
    }
    while(i <= mid)
    {
        b[k] = arr[i];
        i ++;
        k ++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j ++;
        k ++;
    }
     for(i=low;i<=high;i++)
    {
        arr[i]=b[i];
    }
}
void merge_sort(int n, int arr[100], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(n, arr, low, mid);
        merge_sort(n, arr, mid + 1, high);
        merge(n, arr, low, mid, high);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements :: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements :: " << endl;
    for (int i = 0; i < n; i ++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n-1;
    merge_sort(n, arr, low, high);
    cout << "*****The sorted array is*******" <<endl;
    for (int i = 0; i < n; i ++)
    {
        cout << arr[i] << "\t";
    }
}