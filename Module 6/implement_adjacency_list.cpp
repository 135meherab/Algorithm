#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjlst[N];
int main()
{   
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u >> v;
        adjlst[u].push_back(v);
        // adjlst[v].push_back(u); 
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<"List "<< i << " : ";
        for (int j: adjlst[i])
        {
            cout<< j<< " ";
        }
        cout<<endl;
    }
    

    return 0;
}