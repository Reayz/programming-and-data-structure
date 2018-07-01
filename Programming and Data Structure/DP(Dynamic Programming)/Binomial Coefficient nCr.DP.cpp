/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX = 1003;

ll dp[MAX][MAX];
ll ncr(ll n, ll r)
{
    if(r==1) return n;
    if(n==r or r==0) return 1;
    if(dp[n][r]!=-1) return dp[n][r];
    dp[n][r] = 1ll*ncr(n-1, r) + 1ll*ncr(n-1, r-1);
    return dp[n][r];
}
int main()
{
    memset(dp,-1,sizeof (dp));
    ll n, r;
    while(cin>>n>>r)
        cout<<"nCr = "<<ncr(n,r)<<endl;
    return 0;
}
