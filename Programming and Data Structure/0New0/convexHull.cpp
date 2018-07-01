/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pi acos(-1.0)
#define pb push_back
using namespace std;
typedef long long ll;
const int MAX = 100005;

struct Point{
    ll x, y;
};
Point inp[MAX], tmp[MAX];
stack < Point > S;
vector < Point > ans;
ll sq_dist(Point P, Point Q){
    return (P.x-Q.x)*(P.x-Q.x) + (P.y-Q.y)*(P.y-Q.y);
}
int orientation(Point P, Point Q, Point R){
    ll ret = (Q.y-P.y)*(R.x-Q.x) - (Q.x-P.x)*(R.y-Q.y);
    if(ret<0) return 2;
    else if(ret>0) return 1;
    else return ret;
}
bool cmp(Point X, Point Y){
    int ret = orientation(inp[0],X,Y);
    if(ret==1) return false;
    else if(ret==2) return true;
    else {
        ll dist1 = sq_dist(inp[0],X);
        ll dist2 = sq_dist(inp[0],Y);
        return dist1<dist2;
    }
}
Point nextToTop(){
    Point P = S.top();
    S.pop();
    Point res = S.top();
    S.push(P);
    return res;
}
int convexHull(int N){
    int ymin = inp[0].y, index = 0;
    for(int i=1; i<N; i++){
        if(inp[i].y<ymin || (inp[i].y==ymin && inp[i].x<inp[index].x)){
            ymin = inp[i].y;
            index = i;
        }
    }
    swap(inp[0], inp[index]);
    sort(&inp[1], &inp[N], cmp);
    S.push(inp[0]);
    for(int i=1; i<N; i++){
        while(S.size()>1 && orientation(nextToTop(),S.top(),inp[i])!=2)
            S.pop();
        S.push(inp[i]);
    }
    int cnt = 0;
    while(!S.empty()){
        tmp[cnt++]=S.top();
        S.pop();
    }
    ans.clear();
    for(int i=cnt-1; i>=0; i--) ans.pb(tmp[i]);
    return ans.size();
}
int main(){
    int t; scanf("%d",&t);
    for(int tc=1; tc<=t; tc++){
        int n; scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%lld %lld",&inp[i].x, &inp[i].y);
        int tot = convexHull(n);
        cout<<tot<<endl;
        for(int i=0; i<tot; i++) cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
    return 0;
}
