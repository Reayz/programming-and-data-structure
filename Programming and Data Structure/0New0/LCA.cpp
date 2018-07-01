/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pb push_back
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
const int MAX = 100005;

int level[MAX];
int parent[MAX];
int sparse[MAX][24];
vector<int>graph[MAX];
void dfs(int par, int u){
    parent[u]=par;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++){
        int v = graph[u][i];
        if(par==v) continue;
        level[v]=level[u]+1;
        dfs(u,v);
    }
}
void sparse_table(int n){
    mem(sparse, -1);
    for(int i=0; i<n; i++) sparse[i][0] = parent[i];
    for(int j=1; (1<<j)<n; j++){
        for(int i=0; i<n; i++){
            if(sparse[i][j-1]!=-1) sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }
}
int LCA(int p, int q){
    if(level[p]<level[q]) swap(p,q);
    int lg = log2(level[p])+1;
    for(int i=lg; i>=0; i--){
        if(level[p]-(1<<i) >= level[q]) p = sparse[p][i];
    }
    if(p == q) return p;
    for(int i=lg; i>=0; i--){
        if(sparse[p][i] != -1 and sparse[p][i] != sparse[q][i]){
            p = sparse[p][i]; q = sparse[q][i];
        }
    }
    return parent[p];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int node, edge; cin>>node>>edge;
    for(int i=0; i<edge; i++){
        int u, v; cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    level[0]=0; /// count start with node number 0, and level with 0
    dfs(-1, 0);
    sparse_table(node);
    int q; cin>>q;
    while(q--){
        int x, y; cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
	return 0;
}
