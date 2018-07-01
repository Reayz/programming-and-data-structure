#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int row[MAX],col[MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];

int f(int beg,int end)
{
    if(beg>=end) return 0;
    if(visit[beg][end]) return dp[beg][end];
    int ans=1<<30;
    for(int mid=beg;mid<end;mid++)
    {
        int opr_left=f(beg,mid);
        int opr_right=f(mid+1,end);
        int opr_to_multiply_left_and_right=row[beg]*col[mid]*col[end];
        int total=opr_left+opr_right+opr_to_multiply_left_and_right;
        ans=min(ans,total);
    }
    visit[beg][end]=1;
    dp[beg][end]=ans;
    return dp[beg][end];
}

int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>row[i]>>col[i];
    cout<<f(1,n)<<endl;
    return 0;
}
