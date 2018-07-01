/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000008; ///1e8+8

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

int status[(MAX>>5)+7];
void sieve(){
    status[0]=Set(status[0], 0);
    status[0]=Set(status[0], 1);
    for(int i=4; i<=MAX; i+=2){
        status[i>>5]=Set(status[i>>5], i&31);
    }
    for(int i=3; i*i<=MAX; i+=2){
        if(Cheek(status[i>>5], i&31) == 0) {
        /// same as if(check(status[i/32],i%32)==0)
        for(int j=i*i; j<=MAX; j+=(i<<1)){
            status[j>>5]=Set(status[j>>5], j&31);
            /// same as status[j/32]=Set(status[j/32],j % 32)
            }
        }
    }
}
int main(){
    sieve();
    for(int i=0; i<100; i++){
        if(Cheek(status[i>>5], i&31) == 0) printf("%d ",i);
    }
    return 0;
}
