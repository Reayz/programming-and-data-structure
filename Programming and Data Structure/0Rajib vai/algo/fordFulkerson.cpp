#include<bits/stdc++.h>
using namespace std;

#define mx 2000

vector<int>adj[mx];
int cost[mx][mx];
int r_cost[mx][mx];
int parent[mx];
int visit[mx];

int bfs(int s,int d){
    memset(visit,0,sizeof visit);
    queue<int>Q;
    Q.push(s);
    visit[s] = 1; parent[s] = -1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visit[v] && r_cost[u][v] > 0){
                Q.push(v);
                parent[v] = u; visit[v] = 1;
            }
        }
    }
    return (visit[d] == 1);
}

int fordFulkerson(int s,int d){
    int u,v;
    for(u = 0;u < mx; ++u){
        for(v = 0;v < mx; ++v){
            r_cost[u][v] = cost[u][v];
        }
    }
    memset(parent,0,sizeof parent);
    int max_flow = 0;
    while(bfs(s,d)){
        int path_flow = 1<<20;
        for(v = d;v != s;v = parent[v]){
            u = parent[v];
            path_flow = min(path_flow, r_cost[u][v]);
        }
        for(v = d;v != s;v = parent[v]){
            u = parent[v];
            r_cost[u][v] -= path_flow;
            r_cost[v][u] += path_flow;
        }
        max_flow += path_flow;
        cout << path_flow << '\n';
    }
    return max_flow;
}

int main(){
    int n,p;
    while(cin >> n >> p){
        for(int i=1;i<=p;i++){
            int u,v,f; cin >> u >> v >> f;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u][v] = f;
        }
        int s,d; cin >> s >> d;
        cout << "The maximum flow is " << fordFulkerson(s,d) << endl;
    }
    return 0;
}
