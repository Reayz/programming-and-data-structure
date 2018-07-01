#include<bits/stdc++.h>
using namespace std;

#define MAX 1005
char A[MAX],B[MAX];
int lenA,lenB;
bool visit[MAX][MAX];
int dp[MAX][MAX];
string ans="",ans1="";

int cal_LCS(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0') return 0;
    if(visit[i][j]==1) return dp[i][j];
    int ans=0;
    if(A[i]==B[j]) ans=1+cal_LCS(i+1,j+1);
    else
    {
        int val1=cal_LCS(i+1,j);
        int val2=cal_LCS(i,j+1);
        ans=max(val1,val2);
    }
    visit[i][j]=1;
    dp[i][j]=ans;
    return dp[i][j];
}

void PrintLCS(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0') return ;
    if(A[i]==B[j])
    {
        ans+=A[i];
        PrintLCS(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) PrintLCS(i+1,j);
        else PrintLCS(i,j+1);
    }
}

void Printall(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')
    {
        cout<<ans1<<endl;
        return ;
    }

    if(A[i]==B[j])
    {
        ans1+=B[j];
        Printall(i+1,j+1);
        ans1.erase(ans1.end()-1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) Printall(i+1,j);
        else if(dp[i][j+1]>dp[i+1][j]) Printall(i,j+1);
        else
        {
            Printall(i+1,j);
            Printall(i,j+1);
        }
    }
}

int main()
{
    scanf("%s%s",A,B);
    lenA=strlen(A);
    lenB=strlen(B);
    printf("%d\n",cal_LCS(0,0));
    PrintLCS(0,0);
    cout<<ans<<endl;
    Printall(0,0);
    cout<<ans1<<endl;
    return 0;
}
