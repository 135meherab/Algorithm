#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string> v;
    v.push_back(s);
    int i = 0;
    int cnt = 0;
    if(n%2 == 0)
    {
        for (int j = 0; j < n/2; j++)
        {
            for ( ; i < n; i++)
            {
                if(cnt == 2) break;
                cnt++;
                cout<<v[0][i];  
            }
            if(i < n)cout<<"-";
            cnt = 0;
        }
    }
    else
    {
        for (int j = 0; j < n/2; j++)
        {
            for ( ; i < n; i++)
            {
                if(cnt == 2) break;
                cnt++;
                cout<<v[0][i];  
            }
            if(i == n-1)cout<<v[0][i];
            if(i < n-1)cout<<"-";
            cnt = 0;
        }

    }
    
    return 0;
}