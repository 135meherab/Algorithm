#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> graph[N];
bool visited[N];

bool cycle_detect(int u, int p)
{
    bool cycleExist = false;
    visited[u] = true;
    for (int v:graph[u])
    {
        if(v == p) continue;
        if(visited[v] == true) return true;
        cycleExist = cycleExist | cycle_detect(v,u);
    }   
    return cycleExist;
}

int main()
{   
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool cycleDetect = cycle_detect(1,-1);
    if(cycle_detect) cout<<"cycle detected";
    else cout<<"No cycle detected";
    return 0;
}