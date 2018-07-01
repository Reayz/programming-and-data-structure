#include<bits/stdc++.h>
using namespace std;

int n, arr[100];
vector<int>result;
int taken[100];
int cnt=0;
void call()
{
    //for(int i=1;i<4;i++) cout<<taken[i]<<" ";
    //cout<<endl;
    //for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    //cout<<endl;
    if(result.size()==n)
    {
        cnt++;
        //cout<<endl;
        for(int i=0;i<n;i++) cout<<result[i]<<" ";
        cout<<endl;
        //cout<<endl<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1; result.push_back(arr[i]);
            call();
            taken[i]=0; result.pop_back();
            //cout<<endl;
            //for(int i=1;i<4;i++) cout<<taken[i]<<" ";
            //cout<<endl;
            //for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
            //cout<<endl;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<"Permutation: "<<endl;
    call();
    cout<<"Number of permutation: "<<cnt<<endl;
    return 0;
}
