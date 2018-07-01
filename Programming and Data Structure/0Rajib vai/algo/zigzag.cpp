#include <bits/stdc++.h>
using namespace std;

int arr[105];
int dp[105][2];

int zigzag(int n){
    for(int i = 0;i < n; i++){
        dp[i][0] = 1; dp[i][1] = 1;
    }

    int res = 1;
    for(int i = 1;i < n; ++i){
        for(int j = 0;j < i; j++){
            if(arr[j] < arr[i] && dp[i][0] < dp[j][1] + 1){
                dp[i][0] = dp[j][1] + 1;
            }
            if(arr[j] > arr[i] && dp[i][1] < dp[j][0] + 1){
                dp[i][1] = dp[j][0] + 1;
            }
        }

        if(res < max(dp[i][0] , dp[i][1])){
            res = max(dp[i][0] , dp[i][1]);
        }
    }

    return res;
}

int main(){
    int n; cin >> n;
    for(int i = 0;i < n; ++i) cin >> arr[i];
    cout << zigzag(n) << '\n';

    return 0;
}
