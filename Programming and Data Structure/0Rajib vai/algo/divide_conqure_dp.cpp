// Hacker Rank IOI 2014 Practice Contest 2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll inp[8888];
ll cost[8008];
ll dp[808][8008];

ll _find(int l, int r){
    return (cost[r] - cost[l - 1]) * (r - l + 1);
}

void go(int part, int jleft, int jright, int kleft, int kright){
    if(jleft > jright){
        return ;
    }

    int mid = (jleft + jright) / 2;
    ll tot = 1ll * 1e18; int idx = kright;
    for(int i = kleft; i <= min(kright, mid); i++){
        if(dp[part - 1][i - 1] + _find(i, mid) < tot){
            tot = dp[part - 1][i - 1] + _find(i, mid);
            idx = i;
        }
    }

    dp[part][mid] = tot;

    go(part, jleft, mid - 1, kleft, idx);
    go(part, mid + 1, jright, idx, kright);
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> inp[i];
    }
    for(int i = 1; i <= n; i++){
        cost[i] = cost[i - 1] + inp[i];
        dp[1][i] = cost[i] * i;
    }

    for(int i = 2; i <= k; i++){
        go(i, 1, n, 1, n);
    }

    cout << dp[k][n] << '\n';
}
