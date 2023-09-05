#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
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
    cin>>n;
    e =  n-1;
    set_parent(n);
    vector<pair<int,int>> v;
    vector<pair<int,int>> cycle_node[n];
    vector<pair<int,int>> node_connection[n];
    bool cycle = false;
    int cnt_cycle = 0;
    int i = 0;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        
        int leader_A = find_leader(a);
        int leader_B = find_leader(b);
        if(leader_A == leader_B) 
        {
            cycle = true;
            cnt_cycle++;
            cycle_node[i].push_back({a,b});
            i++;
        }
        dsu_union(a,b);
        
    }
    int j = 0;
    for (int i = 2; i <= n; i++)
    {
        if (find_leader(1) != find_leader(i))
        {
            node_connection[j].push_back({1, i});
            j++;
            dsu_union(1,i);
        }
    }
    if(cycle)
    {
        cout<<cnt_cycle<<endl;
        for(int i  = 0; i < cnt_cycle; i++)
        {
            cout<<cycle_node[i].front().first<<" "<<cycle_node[i].front().second<<" "<<node_connection[i].front().first<<" "<<node_connection[i].front().second<<endl;
            
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}