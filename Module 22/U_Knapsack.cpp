#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapsack(int n, int s, int v[], int w[])
{
    if(n == 0 || s==0) return 0;
    if(dp[n][s] != -1) return dp[n][s];
    if(w[n-1] <= s)
    {
        int option1 = knapsack(n-1,s-w[n-1],v,w) + v[n-1];
        int option2 = knapsack(n-1,s,v,w);
        return dp[n][s] = max(option1,option2);
    }
    else
    {
        return dp[n][s] = knapsack(n-1,s,v,w);
    }
}

int main()
{   
    int n,s;
    cin>>n>>s;
    int v[n+1], w[n+1];
    for (int i = 0; i < n; i++)
    {
        cin>>w[i]>>v[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    knapsack(n,s,v,w);
    cout<<dp[n][s];
    
    return 0;
}