/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/

#include<bits/stdc++.h>
using namespace std;

int dp[20];
int function(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    else
    {
        dp[n] = function(n-1) + function(n-2);
        return dp[n];
    }
}
int main()
{
    for(int i=0;i<20;i++) dp[i]=-1;
    int x;
    cin>>x;
    cout<<x<<"th value is: "<<function(x)<<endl;
    main();
    return 0;
}
