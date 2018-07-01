// uva 10304 with knuth optimisation
#include <bits/stdc++.h>
using namespace std;

int inp[301];
int cum[301][301]; // cumulative sum
int dp[301][301]; // dp array
int pa[301][301]; // smallest k that gives optimal answer

/*
  Some Condition
  pa[i][j - 1] <= pa[i][j] <= pa[i + 1][j]
  cum[a][c] + cum[b][d] <= cum[a][d] + cum[b][c], a <= b <= c <= d
  cum[b][c] <= cum[a][d], a <= b <= c <= d
*/

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n; i++){
            scanf("%d", &inp[i]);
        }

        memset(cum, 0, sizeof cum);
        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                cum[i][j] = cum[i][j - 1] + inp[j];
            }
        }

        for(int i = 0; i <= n; i++){
            for(int j = 1; j + i <= n; j++){
                int l = j, r = j + i, mn = 1e9;
                if(i == 0){
                    dp[l][r] = 0;
                    pa[l][r] = l;
                    continue;
                }
                for(int k = pa[l][r - 1]; k <= pa[l + 1][r]; k++){
                    int a = l, b = k - 1, c = k + 1, d = r;
                    if(cum[a][b] + cum[c][d] + dp[a][b] + dp[c][d] < mn){
                        mn = cum[a][b] + cum[c][d] + dp[a][b] + dp[c][d];
                        pa[l][r] = k;
                    }
                }
                dp[l][r] = mn;
            }
        }

        printf("%d\n", dp[1][n]);

        printf("\nFor Tree : \n");

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << pa[i][j] << " ";
            }
            puts("");
        }
    }
    return 0;
}
