/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define MAX 10001

vector<int>matrix[MAX];
queue<int>q;
int visited[MAX], parent[MAX], level[MAX];
void bfs(int n, int src)
{
    q.push(src);
    visited[src]=1;
    level[src]=0;
    parent[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0; i<matrix[u].size(); i++)
        {
            int v = matrix[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                level[v]=level[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
        q.pop();
    }
    for(int i=1; i<=n; i++)
        cout<<"Distance from source("<<src<<") to "<<i<<" is: "<<level[i]<<endl;

    int des;
    cin>>des;
    cout<<"\nPath from "<<src<<" to "<<des<<" is: "<<des<<' ';
    while(parent[des]!=src)
        cout<<parent[des]<<' ', des=parent[des];
    cout<<src<<endl;
}
int main()
{
    //freopen("bfs1.txt", "r", stdin);
    int node, edge;
    cin>>node>>edge;
    while(edge--)
    {
        int x, y;
        cin>>x>>y;
        matrix[x].pb(y);
        matrix[y].pb(x);
    }
    int source;
    cin>>source;
    bfs(node, source);
    return 0;
}
