/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define pb push_back
#define mp make_pair
#define ss stringstream
#define pi acos(-1.0)
#define pI 2.0*acos(0.0)
#define PI 3.141592653589793238
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x , y , sizeof(x))
#define bit_cnt(mask) __builtin_popcount(mask)
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const ll MOD = 1000000007; /// 1e9+7
const int MAX = 100005; ///1e5+5
ll bigmod(ll n, ll r)
{
    if(r==0) return 1;
    if(r==1) return n;
    if(r%2==0)
    {
        ll ret = bigmod(n, r/2);
        return ((ret%MOD) * (ret%MOD)) % MOD;
    }
    else return ((n%MOD) * (bigmod(n,r-1)%MOD)) % MOD;
}
ll modinverse(ll a){return bigmod(a,MOD-2)%MOD;}
ll lcm(ll a, ll b) {a=abs(a); b=abs(b); return (a/__gcd(a,b))*b;}
ll gcd(ll a, ll b) {a=abs(a); b=abs(b); if(!b) return a; return __gcd(b,a%b);}
int in() {int x; scanf("%d",&x); return x;}

struct Point{
    double x, y;
};
double dist(Point P, Point Q){
    return sqrt((P.x-Q.x)*(P.x-Q.x) + (P.y-Q.y)*(P.y-Q.y));
}
/// cw - 1, ccw - 2, linear - 0
int orientation(Point P, Point Q, Point R){
    double ret = (Q.y-P.y)*(R.x-Q.x) - (Q.x-P.x)*(R.y-Q.y);
    if(ret<0) return 2;
    else if(ret>0) return 1;
    else return ret;
}
/// angle of B
double angle(Point A, Point B, Point C){
    double c = dist(A,B);
    double a = dist(B,C);
    double b = dist(C,A);
    return acos((b*b-c*c-a*a)/(-2.0*a*c));
}
double DegToRad(double x){
    return ((pi*x)/180.0);
}
double RadToDeg(double x){
    return ((180.0*x)/pi);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	return 0;
}
