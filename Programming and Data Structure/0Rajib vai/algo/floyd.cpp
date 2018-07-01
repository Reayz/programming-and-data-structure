#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;
const LL infinity=10000000000LL;

LL W[101][101],Q[101][101];

int main()
{
    LL n,e,i,j,k;
    printf("How many node in the graph : ");
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      W[i][j]=0;
    printf("\nHow many edge in the graph : ");
    scanf("%lld",&e);
    printf("\nEnter your edge and cost : \n");
    for(i=1;i<=e;i++)
    {
        LL u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        W[u][v]=w;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(W[i][j]==0) Q[i][j]=infinity;
            else Q[i][j]=W[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
          W[i][j]=min(Q[i][j],Q[i][k]+Q[k][j]);

        for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
           Q[i][j]=W[i][j];
    }

    printf("The sorthest path are : \n");
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
       printf("%lld ",Q[i][j]);
       printf("\n");
    }
    return 0;
}
