#include<bits/stdc++.h>
using namespace std;

struct Point {
    double x , y;

    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

double cross(const Point &O, const Point &A, const Point &B){
    return (long long)(A.x - O.x) * (B.y - O.y) - (long long)(A.y - B.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
    sort(P.begin() , P.end());

    //Build lower hull
    for(int i=0;i<n;i++){
        while(k >= 2 && cross(H[k - 2],H[k - 1],P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    //Build upper hull
    for(int i=n-2,t = k+1;i>=0;i--){
        while(k >= t && cross(H[k - 2],H[k - 1],P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

int main(){
    int test, no = 0; cin >> test;
    while(test--){
        int n; cin >> n;
        vector < Point > P(n) , H(n);
        for(int i=0;i<n;i++){
            cin >> P[i].x >> P[i].y;
        }
        H = convex_hull(P);
        for(int i=0;i<(int)H.size();i++) cout << H[i].x << " " << H[i].y << '\n';
    }
    return 0;
}
