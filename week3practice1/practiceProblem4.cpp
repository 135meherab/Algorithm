#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
vector<string> s;
bool visited[N][N];
int level[N][N];
vector<pair<int,int>> dist = {{0,1},{0,-1},{-1,0},{1,0}};

bool is_valid(int i, int j)
 {
    return (i>= 0 && i<n && j>= 0 && j <m);
 }

void bfs(int si, int sj)
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
        for(pair<int,int> d: dist)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if(is_valid(ni,nj) && !visited[ni][nj] && s[ni][nj] != 'x')
            {
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }
    

}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int si, sj, di, dj;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        for (int j = 0; j < m; j++)
        {
            if(x[j] == 's')
            {
                si = i;
                sj = j;
            }
            if(x[j] == 'e')
            {
                di = i;
                dj = j;
            }
        }
        s.push_back(x);

    }
    bfs(si,sj);
    if(visited[di][dj])cout<<level[di][dj]<<endl;
    else cout<<"-1"<<endl;
    
    return 0;
}