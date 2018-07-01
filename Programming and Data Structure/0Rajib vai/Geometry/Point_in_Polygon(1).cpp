#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-12
const int N = 100005;

typedef long long ll;

struct pt {
    double x,y;
};

pt orig;
pt point[N];

int InsidePolygon(int n){
    int counter = 0;
    double xinters;
    pt p1,p2;

    for(int i=0;i<n;i++){
        p1 = point[i];
        p2 = point[i+1];
        if(orig.y > min(p1.y,p2.y)){
            if(orig.y <= max(p1.y,p2.y)){
                if(orig.x <= max(p1.x,p2.x)){
                    if(p1.y != p2.y){
                        xinters = (orig.y - p1.y)*(p2.x - p1.x)/(p2.y - p1.y) + p1.x;
                        if(p1.x == p2.x || orig.x <= xinters){
                            counter++;
                        }
                    }
                }
            }
        }
    }

    if(counter % 2 == 0) return 0;
    else return 1;
}

int main(){
    int test; cin >> test;
    while(test--){
        int n; cin >> n >> orig.x >> orig.y;
        for(int i=0;i<n;i++){
            cin >> point[i].x >> point[i].y;
        }
        point[n] = point[0];
        puts(InsidePolygon(n) ? "YES" : "NO");
    }
    return 0;
}
