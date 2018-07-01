#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

struct Point {
    int x,y;
};
Point inp[N];
Point p0;
Point nextToTop(stack<Point> &S){
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
int dist(Point p1,Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int orientation(Point p,Point q,Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2){
    Point *p1 = (Point *) vp1;
    Point *p2 = (Point *) vp2;
    int O = orientation(p0, *p1, *p2);
    if(O == 0){
        return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
    }
    return (O == 2) ? -1 : 1;
}
void convex_hull(int n){
    //find the bottommost point
    int ymin = inp[1].y, min = 1;
    for(int i=2;i<=n;i++){
        int y = inp[i].y;
        //Pick the bottom-most or chose the left most point in case of tie
        if((y < ymin) || (ymin == y && inp[i].x < inp[min].x)){
           ymin = inp[i].y, min = i;
        }
    }
    //Place the bottom-most point at first position
    swap(inp[1], inp[min]);
    p0 = inp[1];
    // Sort all point except first point, based on first point
    qsort(&inp[2], n-1, sizeof(Point), compare);
    stack<Point> S;
    S.push(inp[1]);
    S.push(inp[2]);
    S.push(inp[3]);
    for(int i=4;i<=n;i++){
        while(orientation(nextToTop(S),S.top(),inp[i]) != 2)
             S.pop();
        S.push(inp[i]);
    }
    // Show the answer
    while(!S.empty()){
        Point p = S.top();
        cout << p.x << " " << p.y << '\n';
        S.pop();
    }
}
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> inp[i].x >> inp[i].y;
    }
    convex_hull(n);
    return 0;
}
