#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int>m;
    string str;
    while(cin>>str)
    {
        if(str=="exit")
            break;
        m[str]++;
        cout<<str<<" er student "<<m[str]<<endl;
    }
    return 0;
}

