/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define inf 1<<30
using namespace std;
const int MAX = 100005;

int node, edge, d[MAX],edge_u[MAX],edge_v[MAX],edge_cost[MAX];
void bellman_ford(int s){
    for(int i=0; i<=node; i++) d[i]=inf;
    d[s]=0;
    bool neg_cycle=false;
    for(int step=1; step<=node; step++)
    {
        bool updated=false;
        for(int i=1; i<=edge; i++)
        {
            int u=edge_u[i]; int v=edge_v[i];
            if(d[u]+edge_cost[i]<d[v])
            {
                updated=true;
                d[v]=d[u]+edge_cost[i];
                if(step==node) neg_cycle=true;
            }
        }
        if(updated==false) break;
    }
    if(neg_cycle==false) for(int i=1; i<=node; i++) cout<<d[i]<<" ";
    else cout<<"Negative cycle found...:(";
    cout<<endl;
}
int main()
{
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    int s; cin>>s;
    bellman_ford(s);
    return 0;
}
