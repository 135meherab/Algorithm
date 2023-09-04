#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 5;
vector<pii> v[N];
bool visited[N];
class Edge
{
    public: 
         int a;
         int b;
         int w;
         Edge(int a, int b, int w)
         {
            this->a  = a;
            this->b = b;
            this->w = w;
         }
};
class cmp
{
    public:
        bool operator()(Edge a, Edge b)
        {
            return a.w > b.w;
        }
};

void prims(int s,int num_of_node)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s,s,0));
    vector<Edge> edgeList;
    int cnt= 0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if(visited[b]) continue;
        visited[b] = true;
        cnt++;
        edgeList.push_back(parent);
        for (int i = 0; i <v[b].size(); i++)
        {
            pii child = v[b][i];
            if(!visited[child.first])
            {
                pq.push(Edge(b,child.first,child.second));
            }
        }
        
    }
    long long int sum = 0;
    for (Edge valu: edgeList)
    {
        sum += valu.w;
    }
    if(cnt == num_of_node) cout<<sum;
    else cout<<"IMPOSSIBLE";
    
    
}
int main()
{   
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    prims(1,n);
    
    return 0;
}