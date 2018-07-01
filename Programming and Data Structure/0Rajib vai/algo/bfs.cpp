#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

typedef long long LL;
const LL infinity=10000000000LL;

vector<LL>edge[100],cost[100];

LL bfs(LL source,LL destination)
{
    LL d[101],i;
    for(i=0;i<101;i++) d[i]=infinity;
    queue<LL>q;
    q.push(source);
    d[source]=0;
    while(!q.empty())
    {
        LL u=q.front();
        q.pop();
        LL ucost=d[u];
        for(i=0;i<edge[u].size();i++)
        {
            LL v=edge[u][i],vcost=cost[u][i]+ucost;
            if(d[v]>vcost){
              d[v]=vcost;
              q.push(v);
            }
        }
    }
    return d[destination];
}

int main()
{
    LL n,e,i;
    printf("How many node in the graph : ");
    scanf("%lld",&n);
    printf("\nHow many edge in the graph : ");
    scanf("%lld",&e);
    printf("\nEnter your edge and cost : \n");
    for(i=1;i<=e;i++)
    {
        LL u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edge[u].push_back(v);
        cost[u].push_back(w);
    }
    printf("The sorthest path of 1 to n is :  %lld\n",bfs(1,n));
    return 0;
}
