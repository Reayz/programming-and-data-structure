#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[123], rem[123];

ll inv(ll a, ll m){
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if(m == 1) return 0;
    while(a > 1){
        q = a / m;
        t = m;
        m = a % m; a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if(x1 < 0){
        x1 += m0;
    }
    return x1;
}

ll CRT(int n){
    ll prod = 1;
    for(int i = 1; i <= n; i++){
        prod *= num[i];
    }
    ll result = 0;
    for(int i = 1; i <= n; i++){
        ll pp = prod / num[i];
        result += rem[i] * pp * inv(pp, num[i]);
    }
    return (result % prod);
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> rem[i];
    }
    cout << CRT(n) << '\n';
}
