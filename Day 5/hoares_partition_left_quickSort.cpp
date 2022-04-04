#include <bits/stdc++.h>
using namespace std;
vector <int> v;
void interchange (int x, int y)
{
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
int hoares_partition_left (int low, int high)
{
    int i = low;
    int j = high + 1;
    int pivot = v[low];
    while(i < j)
    {
        do
        {
            i = i + 1;
        }while (v[i] < pivot && i <= high);
        do
        {
            j = j - 1;
        }while (v[j] > pivot);
        if (i < j)
        {
            interchange(i, j);
        }
    }
    interchange (j, low);
    return j;
}
void quickSort (int n, int low, int high)
{
    int j;
    if (low < high)
    {
        j = hoares_partition_left(low, high);
        quickSort(n, low, j-1);
        quickSort(n, j+1, high);
    }
}
int main()
{
    int x, n;
    cout << "Enter the number of elements :: " << endl;
    cin >> n;
    cout << "Enter the array elements :: " << endl;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        v.push_back(x);
    }
    int low = 0, high = n-1;
    quickSort(n, low, high);
    cout << "After sorting the array is :: " << endl;
    for (int i = 0; i < n; i ++)
    {
        cout << v[i] << "\t";
    }
    return 0;
}