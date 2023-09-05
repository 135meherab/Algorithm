#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+3;
vector<int> adj_list[N];
bool visited[N];
void dfs(int u)
{
    visited[u] = true;
    for(int v: adj_list[u])
    {
        if(visited[v]== true) continue;
        dfs(v);
    }
}
int main()
{   
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int connectedComponant = 0;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]== true) continue;
        dfs(i);
        connectedComponant++;
    }
    cout<<connectedComponant;
    return 0;
}