#include<bits/stdc++.h>
using namespace std;

int arr[105],dp[150],dir[150];
int n;

int longest(int u)
{
    if(dp[u] != -1) return dp[u];
    int maxi=0;
    for(int v=u+1;v<=n;v++)
    {
        if(arr[v]>arr[u])
        {
            if(longest(v)>maxi)
            {
                maxi=longest(v);
                dir[u]=v;
            }
        }
    }
    dp[u]=1+maxi;
    return dp[u];
}

void print(int start)
{
    while(dir[start]!=-1)
    {
        cout<<arr[start]<<" ";
        start=dir[start];
    }
    cout<<arr[start];
}

int main()
{
    int i,j;
    cout<<"Total number : ",cin>>n;
    for(i=1;i<=n;i++) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);
    int lis=0,start;
    for(i=1;i<=n;i++)
    {
        cout<<"longest path from "<<longest(i)<<endl;
        if(longest(i)>lis)
        {
            lis=longest(i);
            start=i;
        }
    }
    cout<<"LIS = "<<lis<<"  Starting node : "<<start<<endl;
    print(start);
    cout<<endl;
    //for(i=1;i<=10;i++) cout<<dir[i]<<" ";
    return 0;
}
