/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};
double Area(const vector<Point> & inp){
    double res = 0;
    for(int i = 0; i < inp.size(); i++){
        Point p1 = i ? inp[i-1] : inp.back();
        Point p2 = inp[i];
        res += (p1.x - p2.x) * (p1.y + p2.y);
        // res += (p1.x + p2.x) * (p1.y - p2.y);
        // two equation are correct
    }
    return fabs(res)*0.5;
}
int main(){
    int n; cin >> n;
    vector<Point>inp(n);
    // point must be given in cw or ccw order
    for(int i=0;i<n;i++){
        cin >> inp[i].x >> inp[i].y;
    }
    cout << Area(inp) << endl;
    return 0;
}
