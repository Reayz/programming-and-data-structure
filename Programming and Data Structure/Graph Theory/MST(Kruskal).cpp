/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAX = 100005;

struct edge
{
    int u, v, cost;
    bool operator < (const edge &p) const
    {
        return cost < p.cost;
    }
};
int parent[MAX];
vector<edge>vt;
int find(int r)
{
    if(parent[r]==r) return r;
    return find(parent[r]);
}
int mst(int n)
{
    sort(vt.begin(),vt.end());
    for(int i=1; i<=n; i++) parent[i]=i;
    int cnt=0, sum=0;
    for(int i=0; i<vt.size(); i++)
    {
        int u=find(vt[i].u);
        int v=find(vt[i].v);
        if(u!=v)
        {
            parent[u]=v;
            sum += vt[i].cost;
            cnt++;
            if(cnt==n-1) break;
        }
    }
    return sum;
}
int main()
{
    int n, e;
    cin>>n>>e;
    while(e--)
    {
        edge input;
        cin>>input.u>>input.v>>input.cost;
        vt.pb(input);
    }
    cout<<mst(n)<<endl;
    return 0;
}
