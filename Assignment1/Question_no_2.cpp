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
    bool found = false;
    int index;
    int l = 0, r = n-1;
    for (int i = l; i <= r; i++)
    {
        int mid = (l + r)/2;
        if(v[mid] == k)
        {
            index = mid;
            found = true;
            break;
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
    (found) ? cout<<index: cout<<"Not Found";
    
    
    return 0;
}