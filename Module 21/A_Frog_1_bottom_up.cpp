#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int arr[n+1];
    int dp[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);
    for (int i = 3; i <=n; i++)
    {
        int first_choise = dp[i-1] + abs(arr[i] - arr[i - 1]);
        int second_choise = dp[i-2] + abs(arr[i] - arr[i - 2]);
        dp[i] = min(first_choise,second_choise);
    }
    cout<<dp[n];
    return 0;
}