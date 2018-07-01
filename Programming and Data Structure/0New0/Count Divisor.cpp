/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

bool flag[MAX];
int prime[MAX],primecnt;
int divisor[MAX];
void sieve(){
    prime[primecnt++]=2;
    for(int i=3; i<=MAX; i+=2){
        if(!flag[i]){
            prime[primecnt++]=i;
            for(int j=i+i; j<=MAX; j+=i) flag[j]=true;
        }
    }
}
int countdivisor(int x){
    int ans=1;
    for(int i=0; prime[i]*prime[i]<=x; i++){
        int cnt=0;
        while(x%prime[i]==0){
            cnt++;
            x/=prime[i];
        }
        ans *= (cnt+1);
    }
    if(x>1) ans *= 2;
    return ans;
}
int main(){
    sieve();
    for(int i=1; i<=MAX; i++)
        divisor[i]=countdivisor(i);
    int n;
    while(cin>>n)
        cout<<"Number of divisor of "<<n<<" is: "<<divisor[n]<<endl;
    return 0;
}
