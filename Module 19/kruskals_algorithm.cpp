#include <bits/stdc++.h>
using namespace std;
int parent[1001];
class Edge
{
    public:
        int a;
        int b;
        int w;
        Edge(int a, int b, int w)
        {
            this->a = a;
            this->b = b;
            this->w = w;
        }
};
void  set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
    
}

int find_leader(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_unino(int a, int b)
{
    int leader_a = find_leader(a);
    int leader_b = find_leader(b);
    if(leader_a != leader_b)
    {
        parent[leader_b] = leader_a;
    }
}
bool cmp (Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{   
    int n,e;
    cin>>n>>e;
    vector<Edge> v;
    vector<Edge> ans;
    set_parent(n);
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(), v.end(),cmp);
    for(Edge val: v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = find_leader(a);
        int leaderB = find_leader(b);
        if(leaderA == leaderB) continue;
        ans.push_back(Edge(a,b,w));
        dsu_unino(a,b);
    }
    for(Edge val: ans)
    {
        cout<<val.a<<" "<<val.b<<" "<<val.w<<" "<<endl;
    }
    return 0;
}