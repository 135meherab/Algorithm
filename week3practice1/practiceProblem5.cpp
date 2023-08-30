#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
vector<string> s;
bool visited[N][N];
int level[N][N];
pair<int,int> parent[N][N];

vector<pair<int,int>> dist = {{0,-1},{0,1},{1,0},{-1,0}};

bool is_valid(int i, int j)
{
    return (i>=0 && i<n && j>= 0 && j<m);
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj]= true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        int i = u.first;
        int j = u.second;
        q.pop();
        for(pair<int,int> d:dist)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if(is_valid(ni,nj) && !visited[ni][nj] && s[ni][nj] != 'x')
            {
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i,j};
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
            if(x[j]=='e')
            {
                di = i;
                dj = j;
            }
        }
        s.push_back(x);
    }
    
    bfs(si,sj);
    vector<pair<int,int>> path;
    pair<int,int> curr = {di,dj};

    while (!(curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(),path.end());

    if(visited[di][dj])
    {
        cout<<level[di][dj]<<endl;
        for (int i = 1; i <= path.size()-1; i++)
        {
            if(path[i-1].first== path[i].first)
            {
                if(path[i-1].second == path[i].second+1)
                {
                    cout<<"L";
                }
                else cout<<"R";
            }
            else
            {
                if(path[i-1].first == path[i].first+1)
                {
                    cout<<"U";
                }
                else cout<<"D";
            }
        }
    }
    else cout<<"-1";

    
    
    return 0;
}