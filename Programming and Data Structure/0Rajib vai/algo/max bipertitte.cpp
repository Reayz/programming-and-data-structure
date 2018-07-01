#include<bits/stdc++.h>
using namespace std;

int Left[100],Right[100],seen[100];

vector<int>adj[100];

bool kuhu(int u)
{
    int i,v;
    for(i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(seen[v]) continue;
        seen[v]=1;
        if(Right[v]==-1 or kuhu(Right[v]))
        {
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}

int BPM()
{
    memset(Left,-1,sizeof Left);
    memset(Right,-1,sizeof Right);
    int cnt=0,i;
    for(i=0;i<5;i++)
    {
        memset(seen,0,sizeof seen);
        if(kuhu(i)) cnt++;
    }
    return cnt;
}

int main()
{
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<BPM()<<endl;
    return 0;
}
