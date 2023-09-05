#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
class Edge
{
    public:
    long long int a,b,w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
int main()
{   
    int n,e;
    cin>>n>>e;
    vector<Edge> v;
    while (e--)
    {
        long long int a,b,w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    long long int dist[n+1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    long long int s;
    cin>>s;
    dist[s] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            long long int u = ed.a;
            long long int v = ed.b;
            long long int w = ed.w;
            if(dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
        
    }
    bool negetive_cycle = false;

    
    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        long long int u = ed.a;
        long long int v = ed.b;
        long long int w = ed.w;
        if(dist[u] != INF && dist[v] > dist[u] + w)
        {
            negetive_cycle = true;
            break;
            dist[v] = dist[u] + w;
        }
    }
    
    if(negetive_cycle == true) cout<<"Negative Cycle Detected";
    else
    {
        int q;
        cin>>q;
        for (int i = 1; i <= q; i++)
        {
            int d;
            cin>> d;
            if(dist[d] == INF) cout<<"Not Possible"<<endl;
            else cout<<dist[d]<<endl;
        }
        
    }
    return 0;
}