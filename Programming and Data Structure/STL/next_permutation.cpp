#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x, v.push_back(x);
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        cout<<v.at(i)<<" ";

    cout<<endl<<"Loop Start"<<endl<<endl;
    do
    {
        for(int i=0;i<n;i++)
            cout<<v.at(i)<<" ";
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
    cout<<endl<<"Loop End"<<endl<<endl;

    for(int i=0;i<n;i++)
        cout<<v.at(i)<<" ";
    return 0;
}
