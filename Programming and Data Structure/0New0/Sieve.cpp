/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

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
