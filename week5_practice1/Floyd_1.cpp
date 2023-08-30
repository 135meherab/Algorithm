#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);
    int n;
    cin>>n;
    int e;
    int grid[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>> e;
            if(e == -1) grid[i][j] = INF;
            else grid[i][j]= e;
        }
        
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(grid[i][k] + grid[k][j] < grid[i][j])
                {
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
            }
            
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
        
    }

    
    
    return 0;
}