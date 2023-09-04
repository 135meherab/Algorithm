#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
const int INF = 1e9+10;
vector<pair<int,int>> adj_list[N];
vector<int> dist(N,INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({dist[source],source});
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        visited[u] = true;

        for(pair<int,int> vpair: adj_list[u])
        {
            int v = vpair.first;
            int w = vpair.second;

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
        int  u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    dijkstra(1);
    for (size_t i = 1; i<=n; i++)
    {
        cout<<"distance of node "<<i<<": ";
        cout<<dist[i]<<endl;
    }
    
    return 0;
}