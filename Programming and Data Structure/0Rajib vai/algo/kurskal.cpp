#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};

int par[100];
vector<edge>e;

int find(int r)
{
    if(par[r]==r) return r;
    else par[r]=find(par[r]);
}

int mst(int n)
{
    int i;
    sort(e.begin(),e.end());
    for(i=1;i<=n;i++) par[i]=i;

    int count=0,s=0;
    for(i=0;i<(int)e.size();i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            s+=e[i].w;
            if(count==(n-1)) break;
        }
    }
    return s;
}

int main()
{
    int n,m,i;
    cout<<"How  many  node : ";
    cin>>n;
    cout<<"How many edge : ";
    cin>>m;
    for(i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge get;
        get.u=u; get.v=v; get.w=w;
        e.push_back(get);
    }
    cout<<mst(n)<<endl;
    return 0;
}
