#include<bits/stdc++.h>
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
#define MAX 10001

vector<int>graph[MAX];
/// color 0(white), 1(grey), 2(black)
int color[MAX];
pair<int,int>timeV[MAX];
int p[MAX];
int tim, node;
void dfs_visit(int u)
{
    tim++;
    timeV[u].first = tim;
    color[u]=1;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v=graph[u][i];
        if(color[v]==0)
        {
            p[v]=u;
            dfs_visit(v);
        }
    }
    color[u]=2;
    tim++;
    timeV[u].second = tim;
}
void DFS()
{
    tim = 0;
    for(int i=1; i<=node; i++)
    {
        if(color[i]==0) dfs_visit(i);
    }
}
int main()
{
    //freopen("bfs1.txt", "r", stdin);
    int edge;
    cin>>node>>edge;
    while(edge--)
    {
        int x, y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    DFS();

    for(int i=1; i<=node; i++)
        cout<<i<<' '<<timeV[i].first<<' '<<timeV[i].second<<' '<<p[i]<<endl;
    return 0;
}
