#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int adjmtx[N][N];
vector<int> graph[N];
int main()
{   
    int n;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int v;
            cin>>v;
            if(v== 1)
            {
                graph[i].push_back(j);
            }
            
        }
        
    }
    for (int i = 1; i <=n; i++)
    {
        cout<<"list "<< i <<" : ";
        for(int j: graph[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}