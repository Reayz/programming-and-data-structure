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
const int MAX_V = 523;//0000;
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

struct Edge {
    int to, cap, cost, rev;
};

vector < Edge > g[MAX_V];

int h[MAX_V];
int d[MAX_V];
int prevv[MAX_V];
int preve[MAX_V];
int match[MAX_V];

void addEdge(int u, int v, int cap, int cost) {
    g[u].push_back((Edge){v, cap, cost, (int)g[v].size()});
    g[v].push_back((Edge){u, 0, -cost, (int)g[u].size() - 1});
}

pair < int , int > mincostFlow(int s, int t) {
    int flow = 0, flowCost = 0;
    fill(h, h + MAX_V, 0);
    fill(match, match + MAX_V, -1);
    while (true) {
        fill(d, d + MAX_V, INF);
        priority_queue< pii, vector < pii > , greater < pii > > pq;

        d[s] = 0;
        pq.push(pii(d[s], s));

        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            int v = p.se;
            if (d[v] < p.fs) continue;
            for (size_t i = 0; i < g[v].size(); i++) {
                const Edge& e = g[v][i];
                if (e.cap > 0 && d[e.to] > d[v] + e.cost + h[v] - h[e.to]) {
                    d[e.to] = d[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(pii(d[e.to], e.to));
                }
            }
        }

        if (d[t] == INF) break;

        for (int v = 0; v < MAX_V; v++)
            h[v] += d[v];

        int bn = INT_MAX;
        for (int v = t; v != s; v = prevv[v])
            bn = min(bn, g[prevv[v]][preve[v]].cap);

        // // find match
        // for (int v = prevv[t]; v != s; v = prevv[prevv[v]]) {
        //     int u = prevv[v];
        //     match[v] = u;
        //     match[u] = v;
        // }

        flow += bn;
        flowCost += bn * h[t]; // SPFA: res += bn * d[t]

        for (int v = t; v != s; v = prevv[v]) {
            Edge& e = g[prevv[v]][preve[v]];
            e.cap -= bn;
            g[v][e.rev].cap += bn;
        }
    }
    return mp(flow, flowCost);
}


int main(){
    /*addEdge(0, 1, 3, 1);
    addEdge(0, 2, 2, 1);
    addEdge(1, 2, 2, 1);
    pair < int , int > result = mincostFlow(0, 2);
    cout << "Flow : " << result.fs << '\n';
    cout << "Cost : " << result.se << '\n';*/
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            addEdge(i, j + n, 1, x);
        }
    }
    for(int i = 1; i <= n; i++){
        addEdge(0, i, 1, 0);
        addEdge(i + n, n + n + 1, 1, 0);
    }
    cout << mincostFlow(0, n + n + 1).se << '\n';
}
