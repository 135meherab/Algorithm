#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj_list[N];
bool visited[N];
int cnt = 1;

void dfs(int u)
{
    visited[u] = true;
    for (int v: adj_list[u])
    {
        if(visited[v]) continue;
        cnt++;
        dfs(v);
    }
    
}

int main()
{   
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>> u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    vector<int> num_node;
    for (int i = 0; i < 1000; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        num_node.push_back(cnt);
        cnt = 1;
    }
    sort(num_node.begin(),num_node.end());
    for (int val: num_node)
    {
        if(val > 1)
            cout<<val<<" ";
    }
    
}