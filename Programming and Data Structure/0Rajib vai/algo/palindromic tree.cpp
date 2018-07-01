#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100010;

struct node {
    int len;
    int sufflink;
    int num;
    int next[26];
};

int len;
char s[N];
node tree[N];
int num;   // node 1 - root with -1  and node 2 - root with 0
int suff;  // max suffix palindrome
ll ans;

void Init(){
    for(int i = 0;i < N; i++){
        for(int j = 0;j < 26; j++){
            tree[i].next[j] = 0;
        }
        tree[i].sufflink = 0;
        tree[i].num = 0;
        tree[i].len = 0;
    }
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}

bool addLetter(int pos){
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while(true) {
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
            break;
        }
        cur = tree[cur].sufflink;
    }

    if(tree[cur].next[let]){
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if(tree[num].len == 1){
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }


    while(true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
            tree[num].sufflink = tree[cur].next[let];
            break;
        }
    }

    tree[num].num = 1 + tree[tree[num].sufflink].num;

    return true;
}

int main(){
    while(scanf("%s",s)){
        len = strlen(s);

        Init();
        ans = 0;

        for(int i = 0;i < len; i++){
            addLetter(i);
            ans = ans + tree[suff].num;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
