/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[51][51];
int n, cap, price[51], weight[51];
int function(int i, int w)
{
    if(i == n+1) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int profit1 = 0, profit2 = 0;
    if(w+weight[i]<=cap)
        profit1 = price[i] + function(i+1, w+weight[i]);
    profit2 = function(i+1, w);
    dp[i][w] = max(profit1, profit2);
    return dp[i][w];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>price[i];
    cout<<function(1,0);
    return 0;
}
