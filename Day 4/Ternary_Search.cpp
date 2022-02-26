#include <bits/stdc++.h>
using namespace std;
//Write a program in C or C++ to find a given key in array using ternary search algorithm.
bool ternary_search (int key, vector<int>v, int l, int r)
{
    bool z;
    int mid1, mid2;
    if (l <= r)
    {
          mid1 = l + ((r - l) / 3);
          mid2 = r - ((r - l) / 3);
          if (v[mid1] == key)
          {
               z = true;
          }
          else if (v[mid2] == key)
          {
               z = true;
          }
          else if (key < v[mid1])
          {
               return ternary_search(key, v, l, mid1-1);
          } 
          else if (key > v[mid1] && key < v[mid2])
          {
               return ternary_search(key, v, mid1+1, mid2-1);
          } 
          else if (key > v[mid2])
          {
               return ternary_search(key, v, mid2+1, r);
          }
    }
    if (l > r)
    {
          z = false;
    }
    return z;
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
    cout << "Enter the key :: " << endl;
    cin >> key;
    if (n > 0)
    {
        l = 0, r = v.size()-1;
    }
    sort(v.begin(), v.end());
    if (ternary_search(key, v, l, r))
    {
        cout << "Key Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    } 
    return 0;
}
