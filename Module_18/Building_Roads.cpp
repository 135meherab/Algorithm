#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int Level[N];

void set_parent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        Level[i] = 0;
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

void dsu_union(int a, int b)
{
    int leader_a = find_leader(a);
    int leader_b = find_leader(b);
    if(leader_a != leader_b)
    {
        if(Level[leader_a] > Level[leader_b])
        {
            parent[leader_b] = leader_a;
        }
        else if(Level[leader_a] < Level[leader_b])
        {
            parent[leader_a] = leader_b;
        }
        else
        {
            parent[leader_b] = leader_a;
            Level[leader_a]++;
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
    while (e--)
    {   
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    map<int,bool> mp;
    for (int i = 1; i <= n; i++)
    {
        int leader = find_leader(i);
        mp[leader] = true;
    }
    vector<int> v;
    for(auto value:mp)
    {
        v.push_back(value.first);
    }
    cout<<v.size()-1<<endl;
    for (int i = 0; i <= v.size()-1; i++)
    {
       cout<<v[i]<<" ";
    }
    
    return 0;
}