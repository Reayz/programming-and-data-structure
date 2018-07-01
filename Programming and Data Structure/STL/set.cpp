#include<iostream>
#include<set>
using namespace std;

int main()
{
    int x,n;
    set<int>s;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x, s.insert(x);
    set<int> :: iterator i;     //set e data print korte iterator must need
    for(i=s.begin();i!=s.end();i++)
        cout<<*i<<endl;
    return 0;
}
