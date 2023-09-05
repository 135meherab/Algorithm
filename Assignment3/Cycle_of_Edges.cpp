#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int parent_size[100005];
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
    int cnt = 0;
    set_parent(n);
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        int leaderA= find_leader(a);
        int leaderB = find_leader(b);
        if(leaderA == leaderB)
        {
            cnt++;
        }
        dsu_union(a,b);
        
    }
    cout<<cnt;
    return 0;
}