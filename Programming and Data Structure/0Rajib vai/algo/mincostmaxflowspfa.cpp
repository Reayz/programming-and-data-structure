#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define se second
#define pi 2*acos(0)
#define PI 3.14159265358979323846264338

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const int N = 100010;
const int MX = 234;//0000;
const int mod = (int)1e9 + 7;
const int base = 1023456789;
const ull BS1 = 10000019ULL;
const int INF = (1 << 29);

inline int in() {int x; scanf("%d",&x); return x;}
inline ll lin() {ll x; scanf("%lld",&x); return x;}

inline void fastScan(int &x){
    bool negative = false;
    register int c = getchar();
    x = 0;
    for(   ; (c < 48 || c > 57) && (c != '-'); c = getchar());
    if(c == '-'){
        negative = true;
        c = getchar();
    }
    for(   ; (c > 47 && c < 58); c = getchar()){
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(negative)
        x = -x;
}

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

int last[MX];
int pre[N], head[N];
int cap[N], cost[N];
int flow[MX];
int edgeNo[MX];
int par[MX];
int dist[MX];
bool seen[MX];

int edge;

queue < int > Q;

void addEdge(int u, int v, int CAP, int COST){
    head[edge] = v;
    pre[edge] = last[u];
    cap[edge] = CAP;
    cost[edge] = COST;
    last[u] = edge++;

    head[edge] = u;
    pre[edge] = last[v];
    cap[edge] = 0;
    cost[edge] = -COST;
    last[v] = edge++;
}

void Init(){
    memset(last, -1, sizeof last);
    edge = 0;
}

pair < int , int > spfa(int s, int t, int sign){
    int totFlow = 0, totCost = 0;
    while(!Q.empty()){
        Q.pop();
    }
    while(true){
        flow[s] = INF;
        fill(dist, dist + MX, INF);
        dist[s] = 0;
        memset(seen, false, sizeof seen);
        seen[s] = true;
        Q.push(s);
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            seen[u] = false;
            for(int e = last[u]; e >= 0; e = pre[e]){
                int v = head[e];
                int CAP = cap[e];
                int COST = cost[e] * sign;
                if(CAP > 0 && dist[v] > (dist[u] + COST)){
                    dist[v] = dist[u] + COST;
                    flow[v] = min(flow[u], CAP);
                    edgeNo[v] = e; par[v] = u;
                    if(!seen[v]){
                        seen[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
        if(dist[t] == INF) break;
        totCost += flow[t] * dist[t];
        totFlow += flow[t];
        for(int i = t; i != s; i = par[i]){
            cap[edgeNo[i]] -= flow[t];
            cap[edgeNo[i]^1] += flow[t];
        }
    }
    return mp(totFlow, totCost);
}

int main(){
    int test = in();
    while(test--){
        int n = in();
        Init();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x = in();
                addEdge(i, j + n, 1, x);
            }
        }
        for(int i = 1; i <= n; i++){
            addEdge(0, i, 1, 0);
            addEdge(n + i, n + n + 1, 1, 0);
        }
        //addEdge(0, 1, 3, 1);
        //addEdge(0, 2, 2, 1);
        //addEdge(1, 2, 2, 1);
        //addEdge(2, 5, 10, 40);
        //addEdge(3, 5, 10, 30);
        //addEdge(1, 5, 10, 15);
        pii ans = spfa(0, n + n + 1, -1);
        printf("%d\n", ans.se * -1);
    }
}
