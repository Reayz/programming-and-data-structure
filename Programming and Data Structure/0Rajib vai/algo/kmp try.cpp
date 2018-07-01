#include<bits/stdc++.h>
using namespace std;

int pi[10005];
char t[100005];
char p[1005];

void Prefix(){
    int now,len;
    pi[0] = now = -1;
    len = strlen(p);
    for(int i=1;i<len;i++){
        while(now != -1 && p[now + 1] != p[i])
            now = pi[now];
        if(p[now + 1] == p[i]) pi[i] = ++now;
        else pi[i] = now = -1;
    }
}

int KMP(){
    int now,n,m;
    now = -1;
    n = strlen(t); m = strlen(p) - 1;
    for(int i=0;i<n;i++){
        while(now != -1 && p[now + 1] != t[i])
            now = pi[now];
        if(p[now + 1] == t[i]) ++now;
        else now = -1;
        if(now == m) return 1;
    }
    return 0;
}

int Find(){
    int flag;
    Prefix();
    flag = KMP();
    return flag;
}

int main(){
    int test,no = 0; scanf("%d",&test);
    while(test--){
        scanf("%s %s",t,p);
        printf("%s %s\n",t,p);
        if(Find()) printf("Case %d: Yes\n",++no);
        else printf("Case %d: No\n",++no);
    }
    return 0;
}
