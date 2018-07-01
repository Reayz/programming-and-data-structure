/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define inf 1<<28;
using namespace std;

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

int dp[(1<<15)+2], n, w[17][17];
int call(int mask)
{
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ans = inf;
    for(int i=0; i<n; i++)
    {
        if(Cheek(mask, i) == 0)
        {
            int price = w[i][i];
            for(int j=0; j<n; j++)
                if(i != j and Cheek(mask, j)) price += w[i][j];
            int ret = price + call(Set(mask, i));
            //cout<<ret<<" "<<mask<<endl;
            ans = min(ret, ans);
        }
    }
    return dp[mask] = ans;
}
int main()
{
    mem(dp, -1);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>w[i][j];
    cout<<call(0)<<endl;
    return 0;
}
