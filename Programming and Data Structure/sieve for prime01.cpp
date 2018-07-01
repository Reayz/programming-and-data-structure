/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const ll MOD = 1000000007;
const int MAX = 100005;

/// check prime and find prime
bool not_prime[MAX+7];
int prime[MAX+7], cnt_prime;
void sieve(){
    not_prime[0]=true;
    not_prime[1]=true;
    prime[cnt_prime++]=2;
    for(int i=4; i<=MAX; i+=2) not_prime[i]=true;
    for(int i=3; i<=MAX; i+=2){
        if(!not_prime[i]){
            prime[cnt_prime++]=i;
            for(int j=i+i; j<=MAX; j+=i) not_prime[j] = true;
        }
    }
}
int main(){
    sieve();
    int n; cin>>n;
    for(int i=0; i<n; i++) cout<<i<<" "<<not_prime[i]<<endl;
    return 0;
}
