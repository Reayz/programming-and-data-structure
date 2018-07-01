/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define pii pair < int , int >
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define bit_cnt(mask) __builtin_popcount(mask)
using namespace std;
#define MOD 1000000007
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
#define MAX 100005
/// Matrix Exponentiation
/// find the nth Fibonacci number
void matrix_mul(ll x[2][2], ll y[2][2]){
    ll temp[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            temp[i][j]=0;
            for(int k=0; k<2; k++){
                temp[i][j] += (x[i][k]*y[k][j]);
            }
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            x[i][j]=temp[i][j];
        }
    }
}
void matrix_pow(ll r[2][2], ll p){
    if(p==0 or p==1) return;
    matrix_pow(r,p/2);
    matrix_mul(r,r);
    if(p%2){
        ll z[2][2]={{1,1},{1,0}};
        matrix_mul(r,z);              /// if odd, r = r*z
    }
}
ll matrix_exp(ll n){
    if(n<2) return n;             /// 0th term 0, 1st term 1
    ll z[2][2]={{1,1},{1,0}};    /// z is the base term
    matrix_pow(z, n-1);         /// z to the power n-1
    return z[0][0];            /// return nth term
}
int main()
{
    /// find the nth term of fibonacci
    while(true){
        ll n;
        cin>>n;
        cout<<matrix_exp(n)<<endl;
    }
    return 0;
}
