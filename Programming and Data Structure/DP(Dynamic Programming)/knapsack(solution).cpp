/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10
#define MAX_W 1000

int dp[MAX_N][MAX_W], dir[MAX_N][MAX_W];
int n, cap, price[MAX_N], weight[MAX_N];
int call(int i, int w)
{
    if(i == n+1) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int profit1 = 0, profit2 = 0;
    if(w+weight[i]<=cap)
        profit1 = price[i] + call(i+1, w+weight[i]);
    profit2 = call(i+1, w);

    if(profit1>profit2) { dir[i][w] = 1; return dp[i][w] = profit1;}
    else { dir[i][w] = 2; return dp[i][w] = profit2;}
}
void solution(int i, int w)
{
    if(dir[i][w] == -1) return;
    else if(dir[i][w] == 2) solution(i+1, w);
    else if( dir[i][w] ==1)
    {
        cout<<i<<" ";
        solution(i+1, w+weight[i]);
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>price[i];
    cout<<endl<<call(1,0)<<endl;
    cout<<"Solution: ";
    solution(1, 0);
    return 0;
}
