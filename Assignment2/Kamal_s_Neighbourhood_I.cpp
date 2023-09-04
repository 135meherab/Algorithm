#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj_list[N];
int main()
{   
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>> u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int l;
    cin>>l;
    int length = adj_list[l].size();
    cout<<length;
}