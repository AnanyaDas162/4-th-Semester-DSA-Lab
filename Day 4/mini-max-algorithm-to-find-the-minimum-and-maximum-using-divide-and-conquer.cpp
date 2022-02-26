#include <bits/stdc++.h>
using namespace std;
int Max,Min;
/*Write a program in C or C++ to find 
the maximum and minimum number from a given
array using divide and conquer approach.*/
void max_min (vector <int> v, int i, int j)
{
    int mid;
    int  max1, min1;
    if (i == j)
    {
        Max = v[i];
        Min = v[i];
    } 
    else if (j == i + 1)
    {
        if (v[i] > v[j])
        {
             Max = v[i];
             Min = v[j];
        }
        else
        {
             Max = v[j];
             Min = v[i];
        }
    }
    else
    {
        mid = (i + j) / 2;
        max_min(v, i, mid);
		max1=Max;min1=Min;
        max_min(v, mid+1, j); 
        if (Max < max1)
        {
             Max = max1;
        }
        if (Min > min1)
        {
             Min = min1;
        }
    }
}

int main()
{
    int n, x, i, key, l, r;
    vector< int > v;
    cout << "Enter the number of elements :: " << endl;
    cin >> n;
    cout << "Enter the elements :: " << endl;
    for (i = 0; i < n; i ++)
    {
        cin >> x;
        v.push_back(x);
    }
    i = 0;
    int j = v.size()-1;
    max_min(v, i, j);
    cout << "The maximum value is " << Max << endl;
    cout << "The minimum value is " << Min << endl;
    return 0;
}
