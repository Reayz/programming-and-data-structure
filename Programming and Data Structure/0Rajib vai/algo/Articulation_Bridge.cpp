#include<bits/stdc++.h>
using namespace std;

struct Info{
    int u,v;
}Bridge[105];

int node,edge;
vector<int>Graph[105];
int discovery[105];
int low[105];
int tt,kk;

void Art_Bridge(int u,int parent){
    discovery[u] = ++tt;
    low[u] = discovery[u];
    for(int i=0;i<Graph[u].size();i++){
        int v = Graph[u][i];
        if(low[v] == -1){
            Art_Bridge(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > discovery[u]){
                int x = u; int y = v;
                if(x > y) swap(x,y);
                kk++;
                Bridge[kk].u = x; Bridge[kk].v = y;
            }
        }else if(v != parent){
            low[u] = min(low[u],discovery[v]);
        }
    }
}

int main(){
    int test,no = 0; cin >> test;
    while(test--){
        cin >> node >> edge;
        tt = kk = 0;
        memset(low,-1,sizeof low);
        memset(discovery,0,sizeof discovery);
        for(int i=0;i<edge;i++){
            int u,v; cin >> u >> v;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        for(int i=1;i<=node;i++){
            if(low[i] == -1){
                Art_Bridge(i,i);
            }
        }
        for(int i=1;i<=kk;i++) cout << Bridge[i].u << " " << Bridge[i].v << '\n';
        for(int i=1;i<=node;i++) Graph[i].clear();
    }
    return 0;
}
