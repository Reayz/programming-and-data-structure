#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll derangement(int depth, int len, int *d){
    int i, tmp;
    ll ret = 0;
    if(depth == len){
            for(int i = 0;i < len; ++i) cout << d[i] << " ";
            puts("");
        return 1;
    }
    for(i = len - 1;i >= depth; i--){
        if(i == d[depth]) continue;

        tmp = d[i]; d[i] = d[depth]; d[depth] = tmp;
        ret += derangement(depth + 1, len, d);
        tmp = d[i]; d[i] = d[depth]; d[depth] = tmp;
    }

    return ret;
}

ll gen_n(int n){
    int a[30];
    for(int i = 0;i <= n; i++) a[i] = i;
    return derangement(0, n, a);
}

ll sub_fact(int n){
    return n < 2 ? (1 - n) : (sub_fact(n - 1) + sub_fact(n - 2)) * (n - 1);
}

int main(){
    int n; cin >> n;
    cout << gen_n(n) << '\n';
    cout << sub_fact(n) << '\n';
}
