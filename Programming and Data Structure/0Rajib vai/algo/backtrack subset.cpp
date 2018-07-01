#include<bits/stdc++.h>
using namespace std;

bool solution[10];
int arr[10],n;

void backtrack(int a)
{
    if(a==n+1)
    {
        for(int i=1;i<=n;i++)
          if(solution[i]==true) cout<<arr[i]<<" ";
          cout<<endl;
          return ;
    }
    solution[a]=true;
    backtrack(a+1);
    solution[a]=false;
    backtrack(a+1);
}
int main()
{
    int i;
    cout<<"How many number : ";
    cin>>n;
    cout<<"Enter your number : ";
    for(i=1;i<=n;i++) cin>>arr[i];
    backtrack(1);
    return 0;
}
