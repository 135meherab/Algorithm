#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int parent_size[N];
int mx = 0;
void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parent_size[i] = 1;
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
void dsu_union(int a,int b)
{
    int leader_a = find_leader(a);
    int leader_b = find_leader(b);
    if(leader_a != leader_b)
    {
        if(parent_size[leader_a] > parent_size[b])
        {
            parent[leader_b] = leader_a;
            parent_size[leader_a] += parent_size[leader_b];
            mx = max(mx,parent_size[leader_a]);
        }
        else
        {
            parent[leader_a] = leader_b;
            parent_size[leader_b] += parent_size[leader_a];
            mx = max(mx,parent_size[leader_b]);
        }
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);
    
    int n,e;
    cin>>n>>e;
    set_parent(n);
    int cnt_cmpnt = n;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        int ldr_a = find_leader(a);
        int ldr_b = find_leader(b);
        if(ldr_a != ldr_b)
        {
            dsu_union(a,b);
            cnt_cmpnt--;
        }
        cout<<cnt_cmpnt<<" "<<mx<<endl;
    }
    
    return 0;
}