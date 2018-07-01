#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};
double sq(const vector<Point> & fig){
    double res = 0;
    for(unsigned i = 0;i < fig.size(); i++){
        Point p1 = i ? fig[i-1] : fig.back();
        Point p2 = fig[i];
        //cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << '\n';
        res += (p1.x - p2.x) * (p1.y + p2.y);
    }
    return fabs(res)/2;
}

int main(){
    int n;
    while(cin >> n){
        vector<Point>fig(n);
        for(int i=0;i<n;i++){
            cin >> fig[i].x >> fig[i].y;
        }
        cout << sq(fig) << '\n';
    }
    return 0;
}
