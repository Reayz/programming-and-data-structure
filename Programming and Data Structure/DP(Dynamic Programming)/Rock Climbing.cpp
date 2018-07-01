/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x))
#define inf 1<<28;

int mat[][5] = {
    {-1, 2, 5},
    {4, -2, 3},
    {1, 2, 10}
};
int dp[5][5];
int h=3, w=3;
int call(int i, int j)
{
    if(i>=0 && i<h && j>=0 && j<w)
    {
        if(dp[i][j] != -1) return dp[i][j];
        int ret = -inf;

        ret = max(ret, mat[i][j]+call(i+1,j));
        ret = max(ret, mat[i][j]+call(i+1,j-1));
        ret = max(ret, mat[i][j]+call(i+1,j+1));

        return dp[i][j] = ret;
    }
    else return 0;
}
int main()
{
    mem(dp,-1);
    cout<<call(0,0)<<endl;
    return 0;
}
