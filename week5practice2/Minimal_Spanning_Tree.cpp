#include <bits/stdc++.h>
using namespace std;
int parent[20005];
class Edge
{
    public:
    int a;
    int b;
    int w;
    Edge(int a,int b,int w)
    {
        this->a= a;
        this->b  = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
void set_parent(int n)
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
        node  = parent[node];
    }
    return node;
}
void dsu_union(int a,int b)
{
    int leader_a = find_leader(a);
    int leader_b = find_leader(b);
    if(leader_a != leader_b)
    {
        parent[leader_b] = leader_a;
    }
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
    sort(v.begin(),v.end(),cmp);

    for(Edge val: v)
    {
        int a = val.a;
        int b = val.b;
        int leaderA = find_leader(a);
        int leaderB = find_leader(b);
        if(leaderA == leaderB) continue;
        ans.push_back(val);
        dsu_union(a,b);
    }
    int sum = 0;
    for(auto val: ans)
    {
        sum += val.w;
    }
    cout<<sum;
    return 0;
}