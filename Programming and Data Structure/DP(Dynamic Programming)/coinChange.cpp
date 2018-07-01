/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x))

int coin[] = {5, 8, 11, 15, 18};
int make;
int dp[6][100];
int coinChange(int i, int amount)
{
    if(i>=5)
    {
        if(make == amount) return 1;
        else return 0;
    }
    if(dp[i][amount] != -1) return dp[i][amount];
    int ret1=0,ret2=0;
    if(amount+coin[i]<=make) ret1 = coinChange(i, amount+coin[i]);
    ret2 = coinChange(i+1, amount);
    dp[i][amount] = ret1 || ret2;
    return dp[i][amount];
}
int main()
{
    while(cin>>make)
    {
        if(make == 0) {cout<<0<<endl; continue;}
        mem(dp,-1);
        cout<<coinChange(0,0)<<endl;
    }
    return 0;
}
