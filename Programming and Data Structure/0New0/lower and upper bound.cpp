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
///lower and upper bound
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int>v;
    v.pb(1);
    v.pb(3);
    v.pb(5);
    v.pb(5);
    v.pb(7);
    cout<<"lower bound"<<endl;
    cout<<"2 = "<<(lower_bound(all(v),2)-v.begin())<<endl;
    cout<<"3 = "<<(lower_bound(all(v),2)-v.begin())<<endl;
    cout<<"5 = "<<(lower_bound(all(v),5)-v.begin())<<endl;
    cout<<"upper bound"<<endl;
    cout<<"2 = "<<(upper_bound(all(v),2)-v.begin())<<endl;
    cout<<"3 = "<<(upper_bound(all(v),3)-v.begin())<<endl;
    cout<<"5 = "<<(upper_bound(all(v),5)-v.begin())<<endl;
	return 0;
}
/*
lower bound
2 = 1
3 = 1
5 = 2
upper bound
2 = 1
3 = 2
5 = 4
*/
