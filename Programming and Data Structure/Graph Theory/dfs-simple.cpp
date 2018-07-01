#include<bits/stdc++.h>
using namespace std;
#define MAX 100

bool visited[MAX];
vector<int>graph[MAX];
void dfs(int u)
{
    visited[u]=true;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(!visited[v])
        {
            visited[v]=true;
            cout<<v<<" ";
            dfs(v);
        }
    }
}
int main()
{
    int node, edge;
    cin>>node>>edge;
    while(edge--)
    {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int source;
    cin>>source;
    cout<<"Visit node in this sequence: "<<source<<" ";
    dfs(source);
    return 0;
}
