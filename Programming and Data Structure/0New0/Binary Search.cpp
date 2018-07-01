/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const ll MOD = 1000000007;
const int MAX = 100005;
///Binary Search
int n, a[MAX];
int BS(int x){
    int low=1, high=n, ans=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>=x) ans=mid, high=mid-1;
        else low=mid+1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    int x; cin>>x;
    cout<<BS(x)<<endl;
	return 0;
}
