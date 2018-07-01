#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 100010;

inline int in() {int x; scanf("%d",&x); return x;}
inline ll lin() {ll x; scanf("%lld",&x); return x;}

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

ll P(ll a, ll b, ll m){
    ll ret = 1ll;
    while(b > 0){
        if(b & 1ll){
            ret = ret * a % m;
        }
        b /= 2ll;
        a = a * a % m;
    }
    return ret;
}

ll pollard_Rho(ll n, ll c){
    ll x, y, d = 1, i = 1, k = 2;
    srand(time(NULL));
    if(n == 1) return n;
    x = rand() % (n - 2) + 2;
    c = rand() % (n - 1) + 1;
    y = x;
    while(d == 1){
        i++;
        x = (P(x, 2, n) + c + n) % n;
        y = (P(y, 2, n) + c + n) % n;
        y = (P(y, 2, n) + c + n) % n;
        d = __gcd(llabs(x - y), n);
        if(d == n) return pollard_Rho(n, c);
        //cout << d << '\n';
    }
    cout << d << '\n';
}

int main(){
    ll n = lin();
    pollard_Rho(n, 1000);
}
