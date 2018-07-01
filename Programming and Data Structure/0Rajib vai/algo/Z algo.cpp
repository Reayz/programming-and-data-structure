#include<bits/stdc++.h>
using namespace std;

char text[105];
int Z[105];

void Z_Algorithm(){
    int pos,st,ed;
    int sz = strlen(text);
    Z[0] = sz;
    for(pos = 1,st = 0,ed = 0; pos < sz; ++pos){
        if(pos <= ed) Z[pos] = min(ed - pos +1, Z[pos - st]);
        while(pos + Z[pos] < sz && text[Z[pos]] == text[pos + Z[pos]]) ++Z[pos];
        if(pos + Z[pos] -1 > ed){
            st = pos; ed = pos + Z[pos] - 1;
        }
    }
}

int main(){
    cin >> text;
    Z_Algorithm();
    for(int i=0;i<strlen(text);i++) cout << Z[i] << " "; cout << '\n';
    return 0;
}
