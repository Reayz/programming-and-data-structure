/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAX = 100005;

vector<int>g1[MAX],g2[MAX],order;
int visit[MAX],belong[MAX];
void dfs1(int node)
{
    if(visit[node]) return ;
    visit[node] = 1;
    for(int i=0;i<(int)g1[node].size();i++)
    {
        int v = g1[node][i];
        dfs1(v);
    }
    order.pb(node);
}
void dfs2(int node,int cnt)
{
    if(visit[node]) return ;
    belong[node] = cnt;
    visit[node] = 1;
    for(int i=0;i<(int)g2[node].size();i++)
    {
        int v = g2[node][i];
        dfs2(v,cnt);
    }
}

int main(){
    int node,edge;
    while(cin >> node >> edge)
    {
        for(int i=1;i<=edge;i++)
        {
            int u,v;
            cin >> u >> v;
            g1[u].pb(v); // original graph
            g2[v].pb(u);    // edge with opposite direction
        }
        memset(visit,0,sizeof visit);
        for(int i=1;i<=node;i++)
        {
            if(visit[i]) continue;
            dfs1(i);
        }
        memset(visit,0,sizeof visit);
        int cnt = 0;
        // start with maximum finishing time
        for(int i=node-1;i>=0;i--)
        {
            if(!visit[order[i]]){
                cnt++;
                dfs2(order[i],cnt);
            }
        }
        for(int i=1;i<=node;i++)
            cout<<"Node "<<i<<" belong to "<<belong[i]<<" SCC"<<endl;
        for(int i=0;i<=node;i++)
        {
            g1[i].clear();
            g2[i].clear();
        }
        order.clear();
    }
    return 0;
}
