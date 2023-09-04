#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<int> g[N];
bool visisted[N];
int level[N];
int parent[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visisted[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:g[u])
        {
            if(visisted[v]) continue;
            q.push(v);
            visisted[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
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
        g[u].push_back(v);
        g[v].push_back(u);

    }
    
    int s,d;
    cin>>s>>d;

    bfs(s);

    cout<<level[d]<<endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<"parent of " << i<<" : " <<parent[i]<<endl;
    // }

    vector<int> path;
    int curr = d;
    while(curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(),path.end());
    for(int node: path ) cout<<node<<" ";
    return 0;
}