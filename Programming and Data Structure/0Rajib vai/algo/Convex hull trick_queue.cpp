// Week 30 D - Poles
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll pos[5555], weight[5555], F[5555];
ll _A[5555], _B[5555];
ll dp[5005][5005];

int pointer;
vector < ll > M;
vector < ll > B;

bool bad(int l1, int l2, int l3){
    return (B[l3] - B[l1]) * (M[l1] - M[l2]) < (B[l2] - B[l1]) * (M[l1] - M[l3]);
}

void add(ll m, ll b){
    M.push_back(m);
    B.push_back(b);
    while(M.size() >= 3 && bad(M.size()-3,M.size()-2,M.size()-1)){
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}

ll query(ll x){
    if(pointer >= M.size()){
        pointer = M.size() - 1;
    }
    pointer = M.size() - 1;
    while((pointer - 1 >= 0) && (B[pointer] - M[pointer] * x) < (B[pointer - 1] - M[pointer - 1] * x)){
        pointer--;
        //B.erase(B.end() - 1); M.erase(M.end() - 1);
    }
    return B[pointer] - M[pointer] * x;
}

void P(){
    int sz = M.size();
    for(int i = 0; i < M.size(); i++){
        cout << M[i] << " " << B[i] << '\n';
    }
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = n; i >= 1; i--){
        scanf("%lld %lld", &pos[i], &weight[i]);
    }

    for(int i = 1; i <= n; i++){
        _A[i] = weight[i] + _A[i - 1];
        _B[i] = pos[i] * weight[i] + _B[i - 1];
        dp[i][1] = _B[i] - pos[i] * _A[i];
        F[i] = dp[i][1];
    }

    for(int i = 1; i <= n; i++){
        //cout << dp[i][1] << " " ;
    }
    //puts("");

    for(int i = 2; i <= k; i++){
        M.clear(); B.clear();
        add(_A[i - 1], -dp[i - 1][i - 1] + _B[i - 1]);
        for(int j = i; j <= n; j++){
            //P();
            dp[j][i] = -query(pos[j]) + F[j];
            //cout << i << " = " << dp[j][i] << " \n" ;
            add(_A[j], -dp[j][i - 1] + _B[j]);
        }
    }
    printf("%lld\n", dp[n][k]);
}
