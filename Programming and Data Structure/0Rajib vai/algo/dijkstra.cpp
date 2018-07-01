#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

typedef long long LL;
const LL infinity=10000000000LL;

vector<LL>edge[101],cost[101];

struct data{
    LL city,dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
 };

 LL dijkstra(LL source,LL destination)
 {
     LL d[101],i;
     for(i=0;i<101;i++) d[i]=infinity;
     priority_queue<data>q;
     data u,v;
     u.city=source,u.dist=0;
     q.push(u);
     d[source]=0;
     while(!q.empty())
     {
         u=q.top(); q.pop();
         LL ucost=d[u.city];
         for(i=0;i<edge[u.city].size();i++)
         {
             v.city=edge[u.city][i];
             v.dist=cost[u.city][i]+ucost;
             if(d[v.city]>v.dist){
                 d[v.city]=v.dist;
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
    printf("The sorthest path of 1 to n is :  %lld\n",dijkstra(1,n));
    return 0;
}
