#include <bits/stdc++.h>
using namespace std;

int n;
int piles[105];
int Grundy[1005]; // size is depend on max element of piles

int CalculateGrundy(int n){
    // anyone can remove positive integer up-to 3
    Grundy[0] = 0;
    Grundy[1] = 1;
    Grundy[2] = 2;
    Grundy[3] = 3;

    if(Grundy[n] != -1){
        return Grundy[n];
    }

    set < int > Set;

    for(int i = 1;i <= 3; ++i){
        Set.insert(CalculateGrundy(n - i));
    }

    int mex = 0;
    while(Set.find(mex) != Set.end()){
        mex++;
    }

    return Grundy[n] = mex;
}

int main(){
    cin >> n;
    for(int i = 0;i < n; ++i) cin >> piles[i];

    memset(Grundy, -1, sizeof Grundy);
    for(int i = 0;i < n; i++){
        CalculateGrundy(piles[i]);
    }

    int sum = Grundy[ piles[0] ];
    for(int i = 1;i < n; ++i){
        sum = sum ^ Grundy[ piles[i] ];
    }

    if(sum > 0) cout << "Player 1 will won\n"; // As he starts first
    else cout << "Player 2 will won\n";

    return 0;
}
