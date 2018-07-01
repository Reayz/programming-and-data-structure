/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x))

ll M=1000000007;
ll function(ll n, ll r)
{
    if(r==0) return 1;
    if(r==1) return n;
    if(r%2==0)
    {
        ll ret = function(n, r/2);
        return ((ret%M) * (ret%M)) % M;
    }
    else return ((n%M) * (function(n,r-1)%M)) % M;
}
int main()
{
    ll x, y;
    while(cin>>x>>y)
        cout<<function(x,y)<<endl;          /// for x^y
    return 0;
}
