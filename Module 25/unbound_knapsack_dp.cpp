#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unbound_knapsack(int i, int s, int v[], int w[])
{
    if(i == 0 || s == 0) return 0;
    if(dp[i][s] != -1) return dp[i][s];
    if(w[i-1] <= s)
    {
        int c1 = v[i-1] + unbound_knapsack(i,s-w[i-1],v,w);
        int c2 = unbound_knapsack(i-1,s,v,w);
        return  dp[i][s] = max(c1,c2);
    }
    else
    {
        return  dp[i][s] = unbound_knapsack(i-1,s,v,w);
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
    memset(dp,-1,sizeof(dp));
    cout<<unbound_knapsack(n,s,val,weight);
    return 0;
}