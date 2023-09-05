#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+3;
vector<int> adj_list[N];
bool visited[N];
stack<int> st;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        st.push(f);
        for(int v: adj_list[f])
        {
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
        }
    }
    
}
int main()
{   
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bfs(1);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}