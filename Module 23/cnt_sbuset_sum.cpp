#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int cnt_sub_sum(int a[], int s, int i)
{
    if(i == 0)
    {
        if(s==0) return 1;
        else return 0;
    }
    if(dp[i][s] != -1) return dp[i][s];
    if(a[i-1]<= s)
    {
        int c1 = cnt_sub_sum(a,s-a[i-1],i-1);
        int c2 = cnt_sub_sum(a,s,i-1);
        return dp[i][s] = c1 + c2;
    }
    else return dp[i][s] = cnt_sub_sum(a,s,i-1);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cnt_sub_sum(a, s, n);
    cout<<dp[n][s];
    return 0;
}