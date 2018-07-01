/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pb push_back
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
const int MAX = 101;
int in() {int x; scanf("%d",&x); return x;}

vector<int>adj[MAX];
int cost[MAX][MAX];     /// original graph er cost
int r_cost[MAX][MAX];   /// residual graph er cost
int parent[MAX];
bool visit[MAX];
bool bfs(int s, int d){
    mem(visit, false);
    queue<int>Q;
    Q.push(s);
    visit[s] = true;
    parent[s] = -1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!visit[v] && r_cost[u][v] > 0){
                Q.push(v);
                parent[v] = u;
                visit[v] = true;
            }
        }
    }
    return visit[d];
}
int fordFulkerson(int s, int d){
    for(int u=0; u<MAX; u++){
        for(int v=0; v<MAX; v++){
            r_cost[u][v] = cost[u][v];
        }
    }
    int max_flow = 0;
    while(bfs(s,d)){    /// has any augmented path
        int path_flow = INT_MAX;
        for(int v=d; v!=s; v=parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, r_cost[u][v]);
        }
        for(int v=d; v!=s; v=parent[v]){
            int u = parent[v];
            r_cost[u][v] -= path_flow;
            r_cost[v][u] += path_flow;
        }
        max_flow += path_flow;
        //printf("This path flow is: %d\n",path_flow);
    }
    return max_flow;
}
int main(){
    int t = in();
    for(int tc=1; tc<=t; tc++){
        int n = in();
        int s = in();
        int d = in();
        int e = in();
        mem(cost, 0);
        for(int i=0; i<e; i++){
            int u = in();
            int v = in();
            int w = in();
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u][v] += w;    /// one directional
        }
        printf("Case %d: %d\n",tc,fordFulkerson(s,d));
        for(int i=0; i<=n; i++) adj[i].clear();
    }
    return 0;
}
