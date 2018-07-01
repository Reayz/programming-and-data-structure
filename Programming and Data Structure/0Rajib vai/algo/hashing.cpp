#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200010;
const ll mod = 1000000009;
const ll p = 999983;

char text[N], pat[N];

ll H[N];

int Robin_Karp(){
    int a = strlen(text);
    int b = strlen(pat);
    int cnt = 0;
    H[0] = 1LL;
    for(int i = 1;i < N; i++) H[i] = (H[i - 1] * p) % mod;

    ll pat_hash = 0, txt_hash = 0;

    for(int i = 0;i < b; i++){
        pat_hash = pat_hash + ((pat[i] - 'a' + 97) * H[b - i - 1]) % mod;
        pat_hash %= mod;
    }

    for(int i = 0;i < b; i++){
        txt_hash = txt_hash + ((text[i] - 'a' + 97) * H[b - i - 1]) % mod;
        txt_hash %= mod;
    }

    for(int i = 0;i <= (a - b); i++){
        if(pat_hash == txt_hash){
            int L = i, R = i + b, j;
            for(j = L;j < R; j++){
                if(text[j] != pat[j - L]) break;
            }
            if(j == R){
                cnt++;
            }
        }
        txt_hash = (((txt_hash - ((text[i] - 'a' + 97) * H[b - 1]) % mod) + mod) * p) % mod + (text[i + b] - 'a' + 97);
        txt_hash %= mod;
    }
    return cnt;
}



int main(){
    scanf("%s%s",text,pat);
    printf("%d\n",Robin_Karp());
}
