#include<bits/stdc++.h>
using namespace std;

struct pt{
    int x,y;
};

pt inp[5];

inline int area(pt a,pt b,pt c){
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

inline bool intersect_1(int a,int b,int c,int d){
    if(a > b) swap(a,b);
    if(c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}

bool intersect(pt a,pt b,pt c,pt d){
    return intersect_1(a.x,b.x,c.x,d.x)
           && intersect_1(a.y,b.y,c.y,d.y)
           && area(a,b,c) * area(a,b,d) <= 0
           && area(c,d,a) * area(c,d,b) <= 0;
}

int main(){
    int test; cin >> test;
    while(test--){
        for(int i=1;i<=4;i++) cin >> inp[i].x >> inp[i].y;
        puts(intersect(inp[1],inp[2],inp[3],inp[4]) ? "Yes" : "No");
    }
    return 0;
}
