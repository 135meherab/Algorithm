#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v1.push_back(val);
    }
    v1.push_back(INT_MIN);
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>val;
        v2.push_back(val);
    }
    v2.push_back(INT_MIN);

    vector<int> final_vector;
    int lp = 0, rp = 0;
    for (int i = 0; i < n+m; i++)
    {
        if(v1[lp] <= v2[rp])
        {
            final_vector.push_back(v2[rp]);
            rp++;
        }
        else
        {
            final_vector.push_back(v1[lp]);
            lp++;
        }
    }
    for (int num: final_vector) cout<<num<<" ";
    
    
    return 0;
}