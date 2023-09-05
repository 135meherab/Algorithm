#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+3;
vector<int> adj_list[N];
bool visited[N];

bool detect_cycle(int u, int p)
{
    bool cycle = false;
    visited[u] = true;
    for (int v: adj_list[u])
    {
        if(v == p) continue;
        if(visited[v]==true) return true;
        cycle = cycle | detect_cycle(v,u);
    }
    return cycle;
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
    bool cycle_exist = detect_cycle(1,-1);
    (cycle_exist) ? cout<<"YES": cout<<"NO";
    return 0;
}