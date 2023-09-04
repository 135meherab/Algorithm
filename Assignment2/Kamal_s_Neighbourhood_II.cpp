#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj_list[N];
bool visited[N];
int cnt = 0;
void dfs(int u)
{
    visited[u] = true;
    for (int v: adj_list[u])
    {
        if(visited[v]) continue;
        cnt++;
        dfs(v);
    }
    
}

int main()
{   
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>> u>>v;
        adj_list[u].push_back(v);
    }
    int l;
    cin>>l;
    dfs(l);
    cout<<cnt;
}