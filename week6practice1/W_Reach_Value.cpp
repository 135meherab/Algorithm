#include <bits/stdc++.h>
using namespace std;
bool can_go = false;
void recur(int n)
{
    if(n == 1)
    {
        can_go = true;
        return;
    }
    long long int ten;
    long long int twenty; 
    if(n % 10 == 0)
    {
        ten = n/10;
        recur(ten);
    }
    if(n % 20==0)
    {
        twenty = n/20;
        recur(twenty);
    }
    
}
int main()
{   
    int t;
    cin>>t;
    int n;
    for (int i = 1; i <= t; i++)
    {
        can_go = false;
        cin>>n;
        recur(n);
        if(can_go) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}