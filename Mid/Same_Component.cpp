#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool visited[N][N];
int n,m;
char grid[N][N];
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
    int si, sj, di, dj;
    cin>>si>>sj;
    cin>>di>>dj;
    dfs(si,sj);
    if(visited[di][dj]) cout<<"YES";
    else cout<<"NO";
    return 0;
}