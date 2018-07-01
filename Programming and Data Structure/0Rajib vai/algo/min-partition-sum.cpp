#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int inp[N];

int findSum(int n){
    int sum = 0;
    for(int i = 0;i < n; i++){
        sum += inp[i];
    }

    bool dp[n + 5][sum + 5];

    for(int i = 0;i <= n; i++){
        dp[i][0] = true;
    }

    for(int i = 1;i <= sum; i++){
        dp[0][i] = false;
    }

    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(inp[i - 1] <= j){
                dp[i][j] |= dp[i - 1][ j - inp[i - 1] ];
            }
        }
    }

    int diff = INT_MAX;
    for(int j = sum / 2; j >= 0; j--){
        if(dp[n][j] == true){
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main(){
    int n; cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> inp[i];
    }
    cout << "Minimum difference between 2 sets is : " << findSum(n) << '\n';
    return 0;
}
