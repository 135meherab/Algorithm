#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
bool visited[N];
int height[N];
void dfs(int u)
{
    visited[u] = true;
    for (int v: graph[u])
    {
        if(visited[v] == true) continue;
        dfs(v);
        height[u] = max(height[u],height[v]+1);
    }
    
}
int main()
{   
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>> u>> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    int x;
    cin>>x;
    cout<< "height of "<< x<<" - "<<height[x];
    return 0;
}