/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;

/// check two line is intersect or not
struct pt {
    double x,y;
};
pt point[5];
double area(pt a, pt b, pt c){
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
bool intersect_1(double a, double b, double c, double d){
    if(a > b) swap(a,b);
    if(c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}
bool intersect(pt a, pt b, pt c, pt d){
    return intersect_1(a.x, b.x, c.x, d.x)
        && intersect_1(a.y, b.y, c.y, d.y)
        && area(a,b,c) * area(a,b,d) <= 0
        && area(c,d,a) * area(c,d,b) <= 0;
}
int main(){
    for(int i=0; i<4; i++) cin>>point[i].x>>point[i].y;
    if(intersect(point[0], point[1], point[2], point[3])) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
	return 0;
}
