#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 100010;
const int MX = 5005;

inline int in() {int x; scanf("%d",&x); return x;}
inline ll lin() {ll x; scanf("%lld",&x); return x;}

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

int n, m;
int work[MX], dist[MX], q[N];

struct Edge {
    int to, rev, f, cap;
};

vector < Edge > G[MX];

void addEdge(int u, int v, int cap){
    Edge a{v, G[v].size(), 0, cap};
    Edge b{u, G[u].size(), 0, 0};
    G[u].pb(a); G[v].pb(b);
}

bool Dinic_bfs(int s, int t){
    fill(dist, dist + n, -1);
    dist[s] = 0;
    int qt = 0;
    q[qt++] = s;
    for(int qh = 0; qh < qt; qh++){
        int u = q[qh];
        for(int i = 0; i < (int)G[u].size(); i++){
            Edge &e = G[u][i];
            int v = e.to;
            if(dist[v] < 0 && e.f < e.cap){
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return (dist[t] >= 0);
}

int Dinic_dfs(int u, int t, int f){
    if(u == t) return f;
    for(int &i = work[u]; i < (int)G[u].size(); i++){
        Edge &e = G[u][i];
        if(e.cap <= e.f) continue;
        int v = e.to;
        if(dist[v] == dist[u] + 1){
            int df = Dinic_dfs(v, t, min(f, e.cap - e.f));
            if(df > 0){
                e.f += df;
                G[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int DinicMaxflow(int s, int t){
    int total = 0;
    while(Dinic_bfs(s, t)){
        fill(work, work + n, 0);
        while(int delta = Dinic_dfs(s, t, INT_MAX)){
            total += delta;
        }
    }
    return total;
}

int main(){
    n = in(), m = in();
    for(int i = 1; i <= m; i++){
        int u = in(), v = in(), c = in();
        addEdge(u, v, c);
    }
    printf("Maximum flow : %d\n", DinicMaxflow(0, n - 1));
}

/*
6 10
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
*/
