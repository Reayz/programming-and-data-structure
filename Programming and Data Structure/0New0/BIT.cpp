/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n, tree[MAX];
// find summation of 1 to idx
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
// add x to index a
void update(int idx, int x){
    while(idx<=n){
        tree[idx]+=x;
        idx += idx & (-idx);
    }
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        update(i,x);
    }
    int q; cin>>q;
    while(q--){
        int a; cin>>a;
        cout<<query(a)<<endl;
    }
    return 0;
}
