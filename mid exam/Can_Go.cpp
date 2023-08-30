#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int INF = 1005;
vector<bool> visited(N);
vector<int> dist(N,INF);
vector<pair<int,int>> grid[N]; 

void dijkstra(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[s] = 0;
    pq.push({dist[s],s});
    while (!pq.empty())
    {
        int i = pq.top().second;
        pq.pop();
        visited[i] = true;
        for (auto v_pair: grid[i])
        {
            int ci = v_pair.first;
            int cw = v_pair.second;
            if(visited[ci]) continue;
            if(dist[i] + cw < dist[ci])
            {
                dist[ci] = dist[i] + cw;
                pq.push({dist[ci],ci});
            }
        }
        
        
    }
    
}

int main()
{   
    long long int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        grid[a].push_back({b,w});
    }
    
    long long int s;
    cin>>s;

    dijkstra(s);
    long long int t;

    cin>>t;
    for (int i = 0; i < t; i++)
    {
        long long int d, dc;
        cin>>d>>dc;
        if(dist[d] <= dc) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    return 0;
}