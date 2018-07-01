#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

vector<int>adj[100];
int time;

struct info
{
    string color;
    int orig;
    int d_time;
    int f_time;
}node[100];

void DFS_VISIT(int u)
{
    time=time+1;
    node[u].d_time=time;
    node[u].color="GRAY";
    for(int j=0;j<adj[u].size();j++)
    {
        int v=adj[u][j];
        if(node[v].color=="WHITE")
        {
            node[v].orig=u;
            cout<<u<<endl;
            DFS_VISIT(v);
        }
    }
    node[u].color="BLACK";
    time=time+1;
    node[u].f_time=time;
}

int main()
{
    int n,e,i;
    cout<<"How many node : ";
    cin>>n;
    cout<<"How many edge : ";
    cin>>e;
    cout<<"Enter  your edges "<<endl;
    for(i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(i=1;i<=n;i++)
    {
        node[i].color="WHITE";
        node[i].orig=0;
    }
    time=0;
    for(i=1;i<=n;i++)
    {
        if(node[i].color=="WHITE"){
            DFS_VISIT(i);
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<node[i].color<<" "<<node[i].orig<<" "<<node[i].d_time<<" "<<node[i].f_time<<endl;
    }
    return 0;
}
