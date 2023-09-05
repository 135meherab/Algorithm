#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int parent_size[100005];
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
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parent_size[i] = 1;
    }
    
}
int  find_leader(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a,int b)
{
    int leader_A = find_leader(a);
    int leader_B = find_leader(b);
    if(leader_A != leader_B)
    {
        if(parent_size[leader_A] > parent_size[leader_B])
        {
            parent[leader_B] = leader_A;
            parent_size[leader_A] += 1;
        }
        else
        {
            parent[leader_A] = leader_B;
            parent_size[leader_B] += 1;
        }
    }
}
int main()
{   
    int n,e;
    cin>>n>>e;
    vector<Edge> v;
    vector<Edge> ans;
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);
    set_parent(n);
    for (Edge val: v)
    {
        int a = val.a;
        int b = val.b;
        int leaderA = find_leader(a);
        int leaderB = find_leader(b);
        if(leaderA == leaderB) continue;
        ans.push_back(val);
        dsu_union(a,b);
    }
    long long int min_cost = 0;
    for (auto val: ans)
    {
        min_cost += val.w;
    }
    if(ans.size() == n-1) cout<<min_cost;
    else cout<<-1;
    
    return 0;
}