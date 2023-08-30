#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;
vector<pair<int,int>> g[N];
int n,m;
vector<int> dist(N,INF);


void bellman_ford(int s)
{
    dist[s] = 0;
    for(int i = 0;i<n;i++)
    {
        for(int u= 1; u<=n; u++ )
        {
            for(auto vpair:g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if(dist[u] != INF && dist[v] > dist[u]+w)
                {
                    dist[v] = dist[u]+w;
                }
            }
        }
    }

}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    cin>>n>>m;
    for (int i = 0; i <m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    
    bellman_ford(1);

    for(int i= 1; i<=n; i++)
    {
        cout<<"distance of "<<i <<" : "<<dist[i]<<endl;
    }
    return 0;
}