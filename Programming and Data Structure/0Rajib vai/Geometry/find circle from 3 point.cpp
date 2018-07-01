#include <bits/stdc++.h>
using namespace std;

struct point {
    double x,y;
};

point inp[5],mid;

point find_Center(){
    double A1,A2,B1,B2,C1,C2,D1,D2;

    //for first line
    A1 = inp[1].y - inp[0].y;
    B1 = inp[0].x - inp[1].x;
    C1 = A1 * inp[0].x + B1 * inp[0].y;

    swap(A1,B1);
    A1 *= -1;

    mid.x = (inp[0].x + inp[1].x) / 2.0;
    mid.y = (inp[0].y + inp[1].y) / 2.0;

    D1 = A1*mid.x + B1*mid.y;
    cout << A1 << " " << B1 << " " << D1 << '\n';

    //for second line
    A2 = inp[2].y - inp[1].y;
    B2 = inp[1].x - inp[2].x;
    C2 = A1 * inp[1].x + B1 * inp[1].y;

    swap(A2,B2);
    A2 *= -1;

    mid.x = (inp[1].x + inp[2].x) / 2.0;
    mid.y = (inp[1].y + inp[2].y) / 2.0;

    D2 = A2*mid.x + B2*mid.y;
    cout << A2 << " " << B2 << " " << D2 << '\n';

    point ret;

    if(inp[0].x == inp[1].x && inp[1].x == inp[2].x){
        ret.x = inp[0].x;
        ret.y = (min(inp[0].y,min(inp[1].y,inp[2].y))+
                max(inp[0].y,max(inp[1].y,inp[2].y))) / 2.0;

        return ret;
    }

    if(inp[0].y == inp[1].y && inp[1].y == inp[2].y){
        ret.y = inp[0].y;
        ret.x = (min(inp[0].x,min(inp[1].x,inp[2].x))+
                max(inp[0].x,max(inp[1].x,inp[2].x))) / 2.0;

        return ret;
    }

    double det = A1 * B2 - A2 * B1;
    if(det == 0){
        //........
    }else{
        ret.x = (B2 * D1 - B1 * D2)/det;
        ret.y = (A1 * D2 - A2 * D1)/det;
    }

    return ret;
}

double P(point a,point b){
    double X = (a.x - b.x), Y = (a.y - b.y);
    return sqrt(X * X + Y * Y);
}

int main(){
    int test; cin >> test;
    while(test--){
        for(int i=0;i<3;i++) cin >> inp[i].x >> inp[i].y;
        point ans = find_Center();

        printf("%0.8lf %0.8lf\n",ans.x,ans.y);
        printf("%0.10lf\n",P(ans,inp[0]));
        printf("%0.10lf\n",P(ans,inp[1]));
        printf("%0.10lf\n",P(ans,inp[2]));
    }
    return 0;
}
