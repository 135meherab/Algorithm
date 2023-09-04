#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool visited[N][N];
int n,m;
char grid[N][N];
int cnt = 0;
bool is_valid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int si, int sj)
{
    if(!is_valid(si,sj)) return;
    if(visited[si][sj]) return;
    if(grid[si][sj] == '-') return;
    visited[si][sj]= true;
    cnt++;
    dfs(si,sj+1);
    dfs(si,sj-1);
    dfs(si-1, sj);
    dfs(si + 1, sj);
    
}
int main()
{   
    cin>>n>>m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
        
    }
    int mn = INT_MAX;
    int cnt_components   = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j] || grid[i][j] == '-') continue;
            cnt = 0;
            dfs(i,j);
            cnt_components++;
            mn = min(mn,cnt);
        }
        
    }
    if(cnt_components != 0) cout<<mn;
    else cout<<"-1";
    
    return 0;
}