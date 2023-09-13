#include <bits/stdc++.h>
using namespace std;
long long int dp[10005];
int solve(int a[], int i)
    {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        
        return  dp[i] = max(c1,c2);
    }
int main()
{   
    int t;
    cin>>t;
    for (int i = 1; i <=t; i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i= 0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        for (int i = n-1; i >= 0; i--)
        {
            int c1 = a[i] + a[i-2];
            int c2  = a[i-1];
        }

        cout<<"Case "<<i<<": "<<solve(a,n-1)<<endl;
        
    }
    
  
        
        
  
    
    return 0;
}