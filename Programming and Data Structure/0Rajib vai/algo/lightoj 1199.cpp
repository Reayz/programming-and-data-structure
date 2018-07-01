#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n;
int piles[N];
int found[N];
int Grundy[N];

int main(){
    for(int i = 1;i < N; ++i){
        for(int j = 0;j < N; ++j) found[j] = 0;
        for(int j = 1;j <= (i / 2); ++j){
            if(j != i - j) found[ Grundy[j] ^ Grundy[i - j] ] = 1;
        }

        int mex = 0;
        while(found[mex] == 1) mex++;

        Grundy[i] = mex;
    }
    for(int i = 0;i < 20; ++i){
        cout << i << " " << Grundy[i] << '\n';
    }
    int test, no = 0; scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i = 0;i < n; ++i) scanf("%d", piles + i);
        printf("Case %d: ",++no);
        int sum = 0;
        for(int i = 0;i < n; ++i){
            sum ^= Grundy[ piles[i] ];
        }

        if(sum > 0) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
