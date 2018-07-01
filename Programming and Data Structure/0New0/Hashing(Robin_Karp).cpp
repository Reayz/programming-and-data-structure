/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;
const int MAX = 100005;
const ll BS = 999983;

string text, pat;
ll H[MAX];
int Robin_Karp(){
    int a = text.size();
    int b = pat.size();
    int cnt = 0;
    H[0] = 1LL;
    for(int i = 1; i < MAX; i++) H[i] = (H[i-1] * BS) % MOD;
    ll pat_hash = 0, txt_hash = 0;
    for(int i = 0; i < b; i++){
        pat_hash += ((pat[i]-'a'+97) * H[b-i-1]) % MOD;   /// +97 for avoid zero & last one is 0
        pat_hash %= MOD;
    }
    for(int i = 0; i < b; i++){
        txt_hash += ((text[i]-'a'+97) * H[b-i-1]) % MOD;
        txt_hash %= MOD;
    }
    for(int i=0; i<=(a - b); i++){
        if(pat_hash == txt_hash){
            int L = i, R = i + b, j;
            for(j = L; j < R; j++){
                if(text[j] != pat[j - L]) break;
            }
            if(j == R) cnt++;
        }
        txt_hash = (( (txt_hash - ((text[i]-'a' + 97)*H[b-1])%MOD) +MOD)*BS)%MOD + (text[i+b]-'a'+97);
        txt_hash %= MOD;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>text>>pat;
    cout<<Robin_Karp()<<endl;
	return 0;
}
