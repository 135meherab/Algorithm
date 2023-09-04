#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    vector<int> v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int k;
    cin>>k;
    int cnt = 1;
    int l = 0, r = n-1;
    for (int i = l; i <= r; i++)
    {
        int mid = (l + r)/2;
        if(v[mid] == k)
        {
            if(v[mid - 1] == k || v[mid + 1] ==k)
            {
                cnt ++;
                break;
            }
        }
        else if(k < v[mid])
        {
            r = mid -1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(cnt>1) cout<<"YES";
    else cout<<"NO";
    
    
    return 0;
}