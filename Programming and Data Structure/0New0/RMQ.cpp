/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
const int MAX = 100005;
int in() {int x; scanf("%d",&x); return x;}

/// all are 0-based
int arr[MAX];
int st[24][MAX];    /// Sparse Table
/// st[i][j] means minimum among 2^i length starting from j
void Compute_ST(int n){
    for(int i=0; i<n; i++) st[0][i] = i;
    for(int k=1; (1<<k)<n; k++){
        for(int i=0; i+(1<<k)<=n; i++){
            int x = st[k-1][i];            /// i theke 2^k-1 length
            int y = st[k-1][i+(1<<k-1)];    /// i+2^(k-1) theke 2^k-1 length
            st[k][i] = (arr[x] <= arr[y] ? x : y);
        }
    }
}
int RMQ(int i,int j){
    int k = log2(j-i);
    int x = st[k][i];           /// i theke 2^k length
    int y = st[k][j-(1<<k)+1];  /// j-2^k+1 theke 2^k length
    return (arr[x] <= arr[y] ? x : y);
}
int main(){
    int t = in();
    while(t--){
        int n = in();
        int q = in();
        for(int i=0; i<n; i++) arr[i] = in();
        mem(st, 0);
        Compute_ST(n);
        while(q--){
            int x = in(); x--;
            int y = in(); y--;
            if(x==y) printf("%d\n",arr[x]);
            else printf("%d\n",arr[RMQ(x,y)]);
        }
    }
    return 0;
}
