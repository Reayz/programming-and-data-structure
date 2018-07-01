#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
const int mx = 510;

int n;
char t[N];
char s[mx][mx];

struct Node {
    int kunt;
    bool vis;
    Node *next[27];
    vector < Node * > Out;
    Node() {
        for(int i = 0;i < 27; i++){
            next[i] = NULL;
        }
        Out.clear();
        vis = false;
        kunt = 0;
    }

    ~Node() {
        for(int i = 1;i < 27; i++){
            if(next[i] != NULL && next[i] != this) {
                delete next[i];
            }
        }
    }
}*root;

void build_Trie(){
    root = new Node();
    for(int i = 0;i < n; i++){
        Node *cur = root;
        for(int j = 0; s[i][j] ; j++){
            int let = s[i][j] - 'a' + 1;
            if(cur->next[let] == NULL) {
                cur->next[let] = new Node();
            }
            cur = cur->next[let];
        }
    }

    queue < Node *> Q;
    for(int i = 0;i < 27; i++){
        if(root->next[i] == NULL){
            root->next[i] = root;
        }else {
            Q.push(root->next[i]);
            root->next[i]->next[0] = root;
        }
    }

    while(!Q.empty()){
        Node *u = Q.front(); Q.pop();
        for(int i = 1;i < 27; i++){
            if(u->next[i]){
                Node *v = u->next[i];
                Node *w = u->next[0];
                while(w->next[i] == NULL){
                    w = w->next[0];
                }
                v->next[0] = w = w->next[i];
                w->Out.push_back(v);
                Q.push(v);
            }
        }
    }
}

void aho_corasick(){
    Node *cur = root;
    for(int i = 0; t[i] ; i++){
        int let = t[i] - 'a' + 1;
        while(cur->next[let] == NULL){
            cur = cur->next[0];
        }
        cur = cur->next[let];
        cur->kunt++;
    }
}

int dfs(Node *cur){
    if(cur->vis) return cur->kunt;
    for(int i = 0;i < (int)cur->Out.size(); i++){
        cur->kunt += dfs(cur->Out[i]);
    }
    cur->vis = true;
    return cur->kunt;
}

int main(){
    int test, kase = 0; scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        scanf("%s",t);
        for(int i = 0;i < n; i++){
            scanf("%s",s[i]);
        }
        build_Trie();
        aho_corasick();
        printf("Case %d:\n",++kase);
        for(int i = 0;i < n; i++){
            Node *cur = root;
            for(int j = 0; s[i][j] ; j++){
                int let = s[i][j] - 'a' + 1;
                cur = cur->next[let];
            }
            printf("%d\n",dfs(cur));
        }
        delete root;
    }
    return 0;
}

/*
1
4
ababacbabc
aba
ba
ac
abc
*/
