/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int inf = 10000007;

/// find minimum in l...r range
int n, q, block;
int BLOCK[400], arr[MAX];
void update(int val, int indx){
    int id=indx/block;
    BLOCK[id]=min(BLOCK[id], val);
}
int query(int L, int R){
    int lid=L/block;
    int rid=R/block;
    if(lid==rid){
        int ret=inf;
        for(int i=L; i<=R; i++) ret=min(ret,arr[i]);
        return ret;
    }
    int m1=inf,m2=inf,m3=inf;
    for(int i=L; i<(lid+1)*block; i++) m1=min(m1,arr[i]);
    for(int i=lid+1; i<rid; i++) m2=min(m2,BLOCK[i]);
    for(int i=rid*block; i<=R; i++) m3=min(m3,arr[i]);
    return min(min(m1,m2),m3);
}
int main()
{
    scanf("%d %d",&n,&q);
    block=sqrt(n);
    for(int i=0; i<=block; i++) BLOCK[i]=inf;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        update(arr[i],i);
    }
    while(q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",query(x,y));
    }
    return 0;
}
