/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int par[MAX];
void Init(int n){
    for(int i=0; i<=n; i++) par[i]=i;
}
int Find(int x){    // Find the parent of x
    if(par[x]==x) return x;
    return par[x] = Find(par[x]);
}
void Union(int a, int b){
    par[Find(b)] = Find(a);
}
int main()
{
    int n; cin>>n;
    Init(n);    // make parent of x, itself
    int q; cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        Union(a,b); // make a common parent
    }
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        if(Find(a)==Find(b)) cout<<"Connected"<<endl;
        else cout<<"Not Connected"<<endl;
    }
    return 0;
}
