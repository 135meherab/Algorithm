#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool recur(ll i,ll n)
{
    if(i > n) return false;
    else if(i == n) return true;
    else
    {
        bool option1 = recur(i * 10, n);
        bool option2 = recur(i * 20, n);
        return option1 || option2;
    }
    
}
int main()
{   
    int t;
    cin>>t;
    ll n;
    for (ll i = 1; i <= t; i++)
    {
        cin>>n;
        
        if(recur(1,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}