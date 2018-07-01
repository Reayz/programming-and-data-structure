#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-7

int main(){
    int test; cin >> test;
    while(test--){
        double r,a,b,c; cin >> r >> a >> b >> c;
        double x0 = - a*c / (a*a + b*b);
        double y0 = - b*c / (a*a + b*b);
        if(c*c > r * r * (a*a + b*b) + EPS){
            puts("no points");
        }else if(abs(c*c - r * r * (a*a + b*b)) < EPS){
            puts("1 point");
            cout << x0 << " " << y0 << '\n';
        }else{
            double d = r * r - c * c / (a*a + b*b);
            double mult = sqrt(d / (a*a + b*b));
            double ax,ay,bx,by;
            ax = x0 + b * mult;
            bx = x0 - b * mult;
            ay = y0 - a * mult;
            by = y0 + a * mult;
            puts("2 points");
            cout << ax << " " << ay << " " << bx << " " << by << '\n';
        }
    }
    return 0;
}
