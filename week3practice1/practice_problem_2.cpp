#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;
vector<pair<int,int>> g[N];
vector<int> dist(N,INF);
bool visited[N];
void dijkstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[s] = 0;
    pq.push({dist[s],s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pair<int,int> pair_v: g[u])
        {
            int v = pair_v.first;
            int w = pair_v.second;
            if(visited[v]) continue;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
        
    }
    
}

int main()
{   
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    
    int s,d;
    cin>>s>>d;
    dijkstra(s);
    cout<<dist[d];
    return 0;
}