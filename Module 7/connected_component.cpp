#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
int ajd_mtx[N][N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    cout<< u <<" ";
    for (int v: adj[u])
    {
        if(visited[v]== true) continue; 
        dfs(v);
    }
    
}

int main()
{   
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m ; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        cout<<"componant "<< j<< " : ";
        dfs(i);
        cout<<endl;
        cc++;
        j++;
    }
    
    return 0;
}
