#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

int main()
{
    int node,edge,i,step;
    int d[MAX],edge_u[MAX],edge_v[MAX],edge_cost[MAX];
    cout<<"Enter number of node and edge : ";
    cin>>node>>edge;
    for(i=0;i<=node;i++) d[i]=100000000;
    d[1]=0;
    cout<<"Enter your edge \n";
    for(i=1;i<=edge;i++) cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    int neg_cycle=false;
    for(step=1;step<=node;step++)
    {
        int updated=false;
        for(i=1;i<=edge;i++)
        {
            int u=edge_u[i]; int v=edge_v[i];
            if(d[u]+edge_cost[i]<d[v])
            {
                updated=true;
                if(step==node) neg_cycle=true;
                d[v]=d[u]+edge_cost[i];
            }
        }
        if(updated==false) break;
    }
    if(neg_cycle==false) for(i=1;i<=node;i++) cout<<d[i]<<" ";
    else cout<<"Negative cycle detected";
    cout<<endl;
    return 0;
}
