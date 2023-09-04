#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<string> g;
int n,m;
vector<pair<int,int>> direction = {{0,-1},{0,1},{1,0},{-1,0}};
bool visited[N][N];
int level[N][N];

bool is_valid(int i,int j)
{
    return (i>=0 && i<n && j >= 0 && j < m);
}
void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;
    while (!q.empty())
    {
        pair<int,int> u = q.front();
        int i = u.first;
        int j = u.second;
        q.pop();

        for(auto d: direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if(is_valid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {
                q.push({ni,nj});
                visited[ni][nj] = true;
            }
        }

    }
    
}

int main()
{   
    cin>>n>>m;
    int si,sj,di,dj;
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
            if(x[j]=='e')
            {
                di = i;
                dj = j;
            }
        }
        g.push_back(x);
    }
    // cout << g[4][3];
    bfs(si,sj);
    // cout<<level[di][dj];
    if(visited[di][dj]) cout<< "YES";
    else cout<<"NO";
    return 0;
}