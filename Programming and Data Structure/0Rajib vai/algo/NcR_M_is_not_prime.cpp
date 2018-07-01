#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
const ll MOD = (ll)1e9 + 7ll;

int f_prime[N];
int prime[N], sz;

vector < pll > factor;
vector < ll > ans;

void Sieve(){
    for(int i = 4; i < N; i += 2){
        f_prime[i] = 1;
    }
    for(int i = 3; i * i <= N; i += 2){
        if(f_prime[i] == 0){
            for(int j = 3 * i; j < N; j += i){
                f_prime[j] = 1;
            }
        }
    }
    prime[++sz] = 2;
    for(int i = 3; i < N; i += 2){
        if(f_prime[i] == 0){
            prime[++sz] = i;
        }
    }
}

void precal(ll p, ll q, ll mod){
    arr[0] = 1ll;
    arr[1] = 1ll;
    ll x = 1ll;
    for(int i = 2; i <= mod; i++){
        if(i % p == 1){
            x = i;
        }else {
            x = 1ll;
        }
        arr[i] = arr[i - 1] * x % mod;
    }
}

ll bigmod(ll n, ll p, ll mod){
    ll ret = 1ll;
    while(p > 0){
        if(p % 2 == 0){
            ret = ret * n % mod;
        }
        p /= 2;
        n = n * n % mod;
    }
    return ret;
}

ll E(ll n, ll p){
    ll ret = 0;
    while(n){
        ret += n/p;
        n = n / p;
    }
    return ret;
}

ll nCr(ll n, ll r, ll p, ll mod){
    ll e = E(n,p) - E(r,p) - E(n-r,p);
    ll mod1 = F(n, mod, p);
    ll mod2 = F(r, mod, p) * F(n-r, mod, p) % mod;
    mod2 = inv(mod2, mod);
    ll ret = bigmod(p, e, mod);
    ret *= mod1; ret %= mod;
    ret *= mod2; ret %= mod;
    return ret;
}

ll Solve(ll n, ll r, ll m){
    factor.clear();
    int mm = m;
    for(int i = 1; i <= sz && (1ll * prime[i] * prime[i]) <= mm; i++){
        if(mm % prime[i] == 0){
            int cnt = 0;
            while(mm % prime[i] == 0){
                mm /= prime[i];
                cnt++;
            }
            factor.pb(mp(1ll * prime[i], cnt));
        }
    }
    if(mm > 1ll){
        factor.pb(mp(mm, 1));
    }

    for(int i = 0; i < factor.size(); i++){
        ll p = factor[i].fs, q = factor[i].se;
        ll num = bigmod(p, q, MOD);
        precal(p, q, num);
        ans.pb(nCr(n, r, p, num));
    }
}

int main(){
    Sieve();
    int test; cin >> test;
    while(test--){
        ll n, r, m;
        cin >> n >> r;
        m = 142857ll;
        cout << Solve(n, r, m) << '\n';
    }
    return 0;
}
