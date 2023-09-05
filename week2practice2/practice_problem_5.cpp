#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+3;
vector<int> adj_list[N];
bool visited[N];

void dfs(int u )
{
    visited[u] = true;
    for (int v: adj_list[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
    
}
void print_component(int u)
{
    visited[u] = true;
    cout<<u<<" ";
    for (int v: adj_list[u])
    {
        if(visited[v]) continue;
        print_component(v);
    }
    
}
int main()
{   
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int cc= 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        cc++;
    }
    cout<<cc<<endl;
    for (int i = 1; i<= n; i++)
    {
        visited[i] = false;
    }
    for (int i = 1, j = 1; i <= n; i++,j++)
    {
        if(visited[i])continue;
        cout<<"component "<< j<<" : ";
        print_component(i);
        cout<<endl;

    }
    
    return 0;
}