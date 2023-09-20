#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int rod_cutting(int i, int s, int v[], int w[])
{
    if( i == 0 || s == 0) return 0;
    if(dp[i][s] != -1) return dp[i][s];
    if(w[i-1]<= s)
    {
        int c1 = v[i-1] + rod_cutting(i,s-w[i-1], v, w);
        int c2 = rod_cutting(i-1,s, v, w);
        return dp[i][s] = max(c1, c2);
    }
    else
    {
        return dp[i][s] = rod_cutting(i-1,s,v,w);
    }
}
int main()
{   
    int n;
    cin>>n;
    int v[n];
    int w[n];
    for(int i = 0; i<n; i++)
    {
        cin>>v[i];
        w[i] = i+1;
    }
    memset(dp,-1,sizeof(dp));
    cout<<rod_cutting(n,n,v,w);
    return 0;
}