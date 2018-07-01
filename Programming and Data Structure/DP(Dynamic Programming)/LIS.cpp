/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;

int n=7, value[]={-100000, 5, 0, 9, 2, 7, 3, 4};
int dp[8], dir[8];
int longest(int u)
{
    if(dp[u]!=-1) return dp[u];
    int maxi=0;
    for(int v=u+1; v<=n; v++)
    {
        if(value[v] > value[u])
        {
            if(longest(v) > maxi)
            {
                maxi=longest(v);
                dir[u]=v;
            }
        }
    }
    dp[u] = 1+maxi;
    return dp[u];
}
void solution(int start)
{
    while(dir[start] != -1)
    {
        cout<<"Index "<<start<<", Value "<<value[start]<<endl;
        start = dir[start];
    }
    cout<<"Index "<<start<<", Value "<<value[start]<<endl;
}
int main()
{
    mem(dp,-1);
    mem(dir,-1);
    int lis=0, start;
    for(int i=1; i<=n; i++)
    {
        if(longest(i)>lis)
        {
            lis=longest(i);
            start=i;
        }
    }
    cout<<"LIS = "<<lis<<", starting point: "<<start<<endl;
    solution(start);
    return 0;
}
