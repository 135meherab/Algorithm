#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e9;
int n,e;
vector<int> dist(N,INF);
vector<pair<pair<int,int>,int>> edge;
void ford_bellman(int s)
{
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto v_pair:edge)
        {
            int u = v_pair.first.first;
            int v = v_pair.first.second;
            int w = v_pair.second;
            if(dist[u] != INF && dist[v]> dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
        
    }
    
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edge.push_back({{a,b},w});
    }
    ford_bellman(1);
    for (int i = 1; i <= n; i++)
    {
        if(dist[i] == INF) cout<<30000<<" ";
        else cout<<dist[i]<<" ";   
    }
    
    
    return 0;
}