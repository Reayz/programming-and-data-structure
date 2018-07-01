/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define inf 1<<29
#define pb push_back
using namespace std;
const int MAX = 100005;

struct node{
    int u, w;
    node(int _u, int _w){
        u = _u;
        w = _w;
    }
    bool operator < ( const node & p ) const {
        return w > p.w;
    }
};
int n, m, dis[MAX];
vector<int>graph[MAX];
vector<int>cost[MAX];
priority_queue<node>q;
void dijstkra(int s){
    for(int i=1;i<=n;i++) dis[i] = inf;
    q.push(node(s,0));
    dis[s] = 0;
    while(!q.empty()){
        node top = q.top(); q.pop();
        int u=top.u;
        for(int i=0;i<(int)graph[u].size();i++){
            int v=graph[u][i];
            if(dis[u] + cost[u][i] < dis[v]){
                dis[v] = dis[u] + cost[u][i];
                q.push(node(v, dis[v]));
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    int s; cin>>s;
    dijstkra(s);
    cout<<"Distance from source to n: "<<dis[n]<<endl;
    return 0;
}
