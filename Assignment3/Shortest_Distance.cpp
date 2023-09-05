#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
int main()
{   
    int n,e;
    cin>>n>>e;
    long long int dist[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if(i == j) 
            {
                dist[i][j] = 0;
            }
        }
        
    }
    
    while (e--)
    {
        long long int a,b,w;
        cin>>a>>b>>w;
        if(dist[a][b] != INF)
        {
            if(dist[a][b] < w)
            {
                continue;
            }
            else
            {
                dist[a][b] = w;
            }
        }
        else
        {
            dist[a][b] = w;
        }
        

    }

    
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
            
        }
        
    }

    
    int q;
    cin>>q;
    for (int i = 1; i <= q; i++)
    {
        long long int x, y;
        cin>>x>>y;
        if(dist[x][y] == INF)cout<<-1<<endl;
        else cout<<dist[x][y]<<endl;
    }
    
    
    return 0;
}