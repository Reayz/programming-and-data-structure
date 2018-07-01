/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n, piles[MAX], Grundy[MAX];
int CalculateGrundy(int n){
    // anyone can remove  1 or 2 or 3 stone
    Grundy[0] = 0;
    Grundy[1] = 1;
    Grundy[2] = 2;
    Grundy[3] = 3;
    if(Grundy[n] != -1) return Grundy[n];

    set < int > Set;
    for(int i = 1;i <= 3; ++i){
        // insert grundy number for possible move
        Set.insert(CalculateGrundy(n - i));
    }
    // find which is not appear in the set
    int mex = 0;
    while(Set.find(mex) != Set.end()){
        mex++;
    }
    return Grundy[n] = mex;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> piles[i];
    memset(Grundy, -1, sizeof Grundy);
    for(int i = 0; i < n; i++){
        CalculateGrundy(piles[i]);
    }
    int xorsum = Grundy[ piles[0] ];
    for(int i = 1; i < n; i++){
        xorsum = xorsum ^ Grundy[ piles[i] ];
    }
    if(xorsum > 0) cout << "Player 1 will won\n"; // As he starts first
    else cout << "Player 2 will won\n";
    return 0;
}
