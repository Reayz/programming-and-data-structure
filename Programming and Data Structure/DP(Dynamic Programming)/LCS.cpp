/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

string A, B;
int dp[MAX][MAX];
bool visit[MAX][MAX];
string ans1, ans2;
int calLCS(int i, int j)
{
    if(A[i] == '\0' or B[j] == '\0') return 0;
    if(visit[i][j]) return dp[i][j];
    int ans=0;
    if(A[i] == B[j]) ans = 1 + calLCS(i+1,j+1);
    else
    {
        int val1 = calLCS(i+1,j);
        int val2 = calLCS(i,j+1);
        ans = max(val1, val2);
    }
    visit[i][j] = 1;
    return dp[i][j] = ans;
}
void printLCS(int i, int j)
{
    if(A[i] == '\0' or B[j] == '\0'){ cout<<ans1<<endl; return;}
    if(A[i] == B[j])
    {
        ans1 += A[i];
        printLCS(i+1, j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}
void printAllLCS(int i, int j)
{
    if(A[i] == '\0' or B[j] == '\0'){ cout<<ans2<<endl; return;}
    if(A[i] == B[j])
    {
        ans2 += A[i];
        printAllLCS(i+1, j+1);
        ans2.erase(ans2.end()-1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) printAllLCS(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1]) printAllLCS(i,j+1);
        else
        {
            printAllLCS(i+1,j);
            printAllLCS(i,j+1);
        }
    }
}
int main()
{
    cin>>A>>B;
    cout<<"LCS = "<<calLCS(0,0);
    cout<<"\nSolution = ";
    printLCS(0,0);
    cout<<"All Solution . . .\n";
    printAllLCS(0,0);
    return 0;
}
