#include <bits/stdc++.h>
using namespace std;

#define Inf (1 << 30)
#define MAXN 505
const int N = 100005;

int inp[MAXN][MAXN];  // container for 2d gird

struct Point {
    int x, y, mx;
    Point() {}
    Point(int x,int y,int mx) : x(x), y(y), mx(mx) {}

    bool operator < (const Point& other) const {
        return mx < other.mx;
    }
};

struct Segtree2d {
    Point T[N]; //TODO: calculate the accurate space
    int n,m;

    // initialize and construct segment tree
    void init(int n,int m){
        this -> n = n;
        this -> m = m;
        build(1, 1, 1, n, m);
    }

    //build a 2d segment tree from data [ (a1,b1) , (a2,b2) ]
    Point build(int node, int a1,int b1,int a2,int b2){
        // out of range
        if(a1 > a2 or b1 > b2){
            return def();
        }

        // if it is only a single index, assign value to node
        if(a1 == a2 and b1 == b2){
            return T[node] = Point(a1, b1, inp[a1][b1]);
        }

        // split the tree into four segments
        T[node] = def();
        T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2)/2, (b1 + b2)/2));
        T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2)/2 + 1, b1, a2, (b1 + b2)/2));
        T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2)/2 + 1, (a1 + a2)/2, b2));
        T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2)/2 + 1, (b1 + b2)/2 + 1, a2, b2));
        return T[node];
    }

    // helper function for query (int ,int ,int ,int )
    Point query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2){
        // if out of range, return dummy
        if(x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2){
            return def();
        }

        //if it is within range, return the node
        if(x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2){
            return T[node];
        }

        Point mx = def();
        mx = maxNode(mx, query(4 * node - 2, a1, b1, (a1 + a2)/2, (b1 + b2)/2, x1, y1, x2, y2));
        mx = maxNode(mx, query(4 * node - 1, (a1 + a2)/2 + 1, b1, a2, (b1 + b2)/2, x1, y1, x2, y2));
        mx = maxNode(mx, query(4 * node + 0, a1, (b1 + b2)/2 + 1, (a1 + a2)/2, b2, x1, y1, x2, y2));
        mx = maxNode(mx, query(4 * node + 1, (a1 + a2)/2 + 1, (b1 + b2)/2 + 1, a2, b2, x1, y1, x2, y2));
        // return maximum value
        return mx;
    }

    // query from range [ (x1 , y1), (x2 , y2)]
    Point query(int x1, int y1, int x2, int y2){
        return query(1, 1, 1, n, m, x1, y1, x2, y2);
    }

    // helper function for update(int, int, int);
    Point update(int node, int a1, int b1, int a2, int b2, int x, int y, int value) {
        if (a1 > a2 or b1 > b2)
            return def();

        if (x > a2 or y > b2 or x < a1 or y < b1)
            return T[node];

        if (x == a1 and y == b1 and x == a2 and y == b2)
            return T[node] = Point(x, y, value);

        Point mx = def();
        mx = maxNode(mx, update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value) );
        mx = maxNode(mx, update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
        mx = maxNode(mx, update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
        mx = maxNode(mx, update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value) );
        return T[node] = mx;
    }

    // update the value of (x, y) index to value
    Point update(int x, int y, int value) {
        return update(1, 1, 1, n, m, x, y, value);
    }

    // these are virtual because they will be overridden in child class
    virtual Point maxNode (Point a, Point b){
        return max(a , b);
    }
    //dummy node
    virtual Point def(){
        return Point(0 , 0, -Inf);
    }
};

struct Segtree2dMin : Segtree2d {
    Point maxNode(Point a, Point b){
        return min(a , b);
    }
    Point def(){
        return Point(0, 0, Inf);
    }
};

Segtree2d Tmax;
Segtree2dMin Tmin;

int main(){
    // input
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n; ++i){
        for(int j = 1;j <= n; ++j){
            scanf("%d", &inp[i][j]);
        }
    }

    // initialize the tree
    Tmax.init(n ,m);
    Tmin.init(n ,m);

    // query input
    int q; scanf("%d",&q);
    for(int i = 1;i <= q; i++){
        int ty; scanf("%d", &ty);
        if(ty == 1){
            int x, y, value;
            scanf("%d %d %d", &x, &y, &value);
            Tmax.update(x, y, value);
            Tmin.update(x, y, value);
        }else{
            int x1 , y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%d\n", Tmax.query(x1, y1, x2, y2).mx);
            printf("%d\n", Tmin.query(x1, y1, x2, y2).mx);
        }

    }
    return 0;
}
