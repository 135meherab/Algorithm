#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 1e9;
int g[N][N];
int n,m;

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(g[i][j]==INF) cout<<"x"<<" ";
            else cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void dist_initialize()
{
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    cin>>n>>m;
    dist_initialize();
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v] = w;
    }
    print_matrix();

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }  
    }
    
    cout<<endl<<"after floyd warshall: "<<endl;
    print_matrix();
    return 0;
}