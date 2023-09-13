#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int make_it(int n, int i)
{
    if(i > n) return dp[i] = 0;
    else if(i == n) return dp[i] = 1;
    else if(dp[i] != -1) return dp[i];
    else
    {
        int c1 = make_it(n, i+3);
        int c2 = make_it(n, i*2);
        return  dp[i] = c1 || c2;
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        make_it(n,1);
        if(dp[n] == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}