#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1005;
int sum[N][N];
int a[11][11];

int maximum_path(int i, int j)
{
    if(i == 0 and j == 0) return a[0][0];
    if( i < 0 or j < 0) return -1e9; 
    int up = a[i][j] + maximum_path(i-1,j);
    int left = a[i][j] + maximum_path(i,j-1);
    return max(up,left);
}

int main()
{   
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    sum[0][0] = a[0][0];
    cout<<maximum_path(n-1,m-1);
    return 0;
}