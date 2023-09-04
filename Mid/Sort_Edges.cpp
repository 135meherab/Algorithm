#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int e;
    cin>>e;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<pair<int,int>> v;
    while (e--)
    {
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    for(int i = 0; i<v.size(); i++)
    {
        pq.push({v[i].first,v[i].second});
    }
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    
    
    return 0;
}