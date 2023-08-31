#include <bits/stdc++.h>
using namespace std;
int parent[1000];
int Level[1000];

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int n,e;
    cin>>n>>e;
    set_parent(n);
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<"leader of "<<i<<" : "<<find_leader(i)<<endl;
    }
    return 0;
}