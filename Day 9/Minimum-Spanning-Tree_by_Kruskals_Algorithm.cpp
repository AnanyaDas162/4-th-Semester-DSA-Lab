#include <bits/stdc++.h>
#include <fstream>
#include <cstdio>
#define m 6
using namespace std;
vector <vector<int>>v;
vector <int> v1;
vector <pair<int, pair<char, char>>> graph, sol;
int parent[m];
int n;
int ans = 0;
int find(int i)
{
    /* All the roots of the sets have -ve 
    parents. So, basically this function 
    returns the root value of a particular
    element of the particular set.*/
    while (parent[i] > 0)
    {
        i = parent[i];
    }
    return i;
}

void setUnion(int i, int j)
{
    int count = parent[i] + parent[j];
    /* Here, Both the vertices i and j
    belong to the two different sets.*/
    //cout << count << endl;
    if (parent[i] < parent[j])
    /* Checking which of the 2 vertices
    has greater number of elements.
    After this, the vertex, having greater number of elements
    is set to the root of the other vertex and the parent element
    of the formar one is set to the count value.*/
    {
        parent[j] = i; 
        parent[i] = count;
    }
    else{
        parent[i] = j;
        parent[j] = count;
    }
}
void make_Set ()
{
    fill (parent, parent + m, -1);
    /*initializing the parent array with -1 to
    denote that all the vertices have their 
    parent -1 to make them disjoint sets.*/
}
void kruskal ()
{
    make_Set(); // Making all the vertices as the disjoint sets.
    sol.clear();
    for (auto i = graph.begin(); i != graph.end();i ++){
        if (find((*i).second.first-65) != find((*i).second.second-65))
        /* Basically the find function checks whether a cycle is being
        made or not.*/
        {
            sol.push_back({(*i).first, {(*i).second.first, (*i).second.second}});
            // These edges are added to the solution
            ans = ans + (*i).first;// Counting the total weight of the MST
            setUnion((*i).second.first-65, (*i).second.second-65);
            // Making the union of the two vertices 
        }
    }
}
void print_2dVector(vector<vector<int>>v2)
{
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            cout << v2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void print_vector_of_pairs(vector <pair<int, pair<char, char>>> g)
{
    for (auto i = g.begin(); i != g.end(); i ++)
    {
        if ((*i).second.first != (*i).second.second && (*i).first > 0)
        {
            cout<<"Weight :: "<<(*i).first<<"     "<<"Edges ::     "<<(*i).second.first<<"    "<<"<-->"<<"    "<<(*i).second.second<< endl;
        }
    }
}

int main()
{
    int x;
    ifstream vertex ("abc.txt");//creating an object of ifstream class
    vertex >> n;//number of vertices
    for (int i = 0; i < n; i++)
    {
        v1.clear();
        for (int j = 0; j < n; j++)
        {
            vertex >> x;
            v1.push_back(x);
            //graph.push_back({x,{i+65, j+65}});
        }
        v.push_back(v1);
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = i; j < n; j ++)
        {
            if (v[i][j] != 0)
            {
                graph.push_back({v[i][j],{i+65, j+65}});//Storing the +ve weights and the two edges
            }
        }
    }
    cout << "The total number of vertices :: " << n << endl;
    cout << "The matrix :: " << endl;
    print_2dVector(v);
    sort(graph.begin(), graph.end()); // Sorting the edges according to the weights in non-decreasing order
    cout << "After sorting :: " << endl;
    print_vector_of_pairs(graph);
    cout << "*********By KRUSKALS Algorithm ********" << endl;
    cout << "The minimum spanning tree is :: " << endl;
    kruskal();
    print_vector_of_pairs (sol);//Printing the MST
    cout << "The weight of minimum spanning tree is :: " << ans << endl;
    return 0;
}
