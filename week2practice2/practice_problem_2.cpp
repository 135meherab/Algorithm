#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+3;
vector<int> adj_list[N];
bool visited[N];
int level[N];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    level[u] = 0;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int v: adj_list[f])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[f] + 1;
        }
        
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
    bfs(1);
    int x;
    cin>>x;
    cout<<"level of "<< x <<" : "<<level[x];
    return 0;
}