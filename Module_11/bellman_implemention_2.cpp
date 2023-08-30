#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9;
int n,m;
vector<pair<pair<int,int>,int>> edge;
vector<int> dist(N,INF);

void bellman_ford(int s)
{
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        for(auto v_pair:edge)
        {
            int u = v_pair.first.first;
            int v = v_pair.first.second;
            int w = v_pair.second;

            if(dist[u] != INF && dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
            }
        }
    }
    

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({{u,v},w});
    }
    bellman_ford(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<"D of " << i <<" : " << dist[i]<<endl;
    }
    
    return 0;
}