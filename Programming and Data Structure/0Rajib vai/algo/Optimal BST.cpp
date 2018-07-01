#include <bits/stdc++.h>
using namespace std;

int inp[1234];
int freq[1234];

int cum[1234][1234];
int dp[1234][1234];

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &inp[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &freq[i]);
    }

    for(int i = 0; i < n; i++){
        dp[i][i] = freq[i];
    }

    for(int i = 0; i < n; i++){
        cum[i][i] = freq[i];
        for(int j = i + 1; j < n; j++){
            cum[i][j] = cum[i][j - 1] + freq[j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", cum[i][j]);
        }
        puts("");
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j + i - 1 < n; j++){
            int l = j, r = j + i - 1, sum, mn;
            sum = cum[l][r]; mn = 1e9;

            for(int k = l; k <= r; k++){
                int a = l, b = k - 1, c = k + 1, d = r, prev = 0;
                if(b >= a) prev += dp[a][b];
                if(c <= d) prev += dp[c][d];

                mn = min(mn, prev);
            }

            dp[l][r] = sum + mn;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", dp[i][j]);
        }
        puts("");
    }
}
