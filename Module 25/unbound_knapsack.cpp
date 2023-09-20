#include <bits/stdc++.h>
using namespace std;
int unbound_knapsack(int i, int s, int v[], int w[])
{
    if(i == 0 || s == 0) return 0;
    if(w[i-1] <= s)
    {
        int c1 = v[i-1] + unbound_knapsack(i,s-w[i-1],v,w);
        int c2 = unbound_knapsack(i-1,s,v,w);
        return max(c1,c2);
    }
    else
    {
        return unbound_knapsack(i-1,s,v,w);
    }
}
int main()
{   
    int n,s;
    cin>>n>>s;
    int val[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    cout<<unbound_knapsack(n,s,val,weight);
    return 0;
}