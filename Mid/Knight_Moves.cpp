#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n,m;
vector<pair<int,int>> direc = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2}, {-1,2}, {1,-2}, {-1,-2}};
bool visited[N][N];
int level[N][N];

bool isvalid(int i, int j)
{
    return (i>= 0 && i<n && j>= 0 && j<m);
}
void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int,int> u = q.front();
        int i = u.first;
        int j = u.second;
        q.pop();
        for (auto d: direc)
        {
            int ni= i+ d.first;
            int nj = j + d.second;
            if(isvalid(ni,nj) && visited[ni][nj] != true)
            {
                visited[ni][nj]= true;
                level[ni][nj] = level[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }
}
int main()
{   
    int t;
    cin>>t;
    while (t--)
    {
        
        cin>>n>>m;
        int ki,kj,qi,qj;
        cin>>ki,kj;
        cin>>qi,qj;
    }
    
    return 0;
}