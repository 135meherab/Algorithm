#include <bits/stdc++.h>
using namespace std;

bool found = false;
int n;

void expretion(int x, int i, long long int sum, long long int a[])
{
    if(i == n)
    {
        if(x == sum) found = true;
        return;
    }
    long long int add_sum = sum + a[i];
    long long int sub_sum = sum - a[i];
    expretion(x,i+1, add_sum, a);
    expretion(x,i+1,sub_sum,a);
}
int main()
{   
    int x;
    cin>>n>>x;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    expretion(x,1,a[0],a);
    if(found) cout<<"YES";
    else cout<<"NO";
    return 0;
}