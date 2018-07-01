#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int modulo(ll a,ll b,ll c){
    long long x = 1,y = a;
    while(b > 0){
        if(b%2 == 1){
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

ll mulmod(ll a,ll b,ll c){
    ll x = 0,y = a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b /= 2;
    }
    return (x % c);
}

bool Fermat(long long p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        long long a = rand()%(p-1)+1;
        // modulo is the function we developed above for modular exponentiation.
        if(modulo(a,p-1,p) != 1){
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}

bool Miller(ll p,int iter){
    if(p < 2) return false;
    if(p != 2 && p%2 == 0) return false;
    ll s = p - 1;
    while(s%2 == 0) s/=2;
    for(int i=1;i<=iter;i++){
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a,temp,p);
        while(temp != p-1 && mod != 1 && mod != p-1){
            mod = mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod != p-1 && temp%2 == 0) return false;
    }
    return true;
}

int main(){

    /*ll a , b, c; cin >> a >> b >> c;
    cout << modulo(a,b,c) << '\n';

    ll x,y,z; cin >> x >> y >> z;
    cout << mulmod(x,y,z) << '\n';*/

    ll p; int iter; cin >> p >> iter;
    puts(Fermat(p,iter) ? "Prime" : "Not prime");

    puts(Miller(p,iter) ? "Prime" : "Not prime");

    return 0;
}
