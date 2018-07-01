#include<bits/stdc++.h>
using namespace std;

#define MAXN 10005

struct pt {
    int x, y, id;
};

pt a[MAXN];

double mindist;
int ansa,ansb;

inline bool cmp_x (const pt & a, const pt & b){
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b){
    return a.y < b.y;
}

inline void upd_ans (const pt & a, const pt & b){
    double dist = sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + 0.0);
    if(dist < mindist){
        mindist = dist, ansa = a.id, ansb = b.id;
    }
}

void Solve (int l,int r){
    if(r - l <= 3){
        for(int i=l; i<=r; i++){
            for(int j=i+1; j<=r; j++){
                upd_ans(a[i], a[j]);
            }
        }
        sort(a+l, a+r+1, &cmp_y);
        return ;
    }
    int m = (l + r) >> 1;
    int midx = a[m].x;
    Solve(l, m); Solve(m+1, r);
    static pt t[MAXN];
    merge(a+l, a+m+1, a+m+1, a+r+1, t, &cmp_y);
    copy(t, t+r-l+1, a+l);

    int tsz = 0;
    for(int i=l; i<=r; i++){
        if(abs(a[i].x - midx) < mindist){
            for(int j=tsz-1; j>=0 && a[i].y - t[j].y < mindist; j--){
                upd_ans(a[i], t[j]);
            }
            t[tsz++] = a[i];
        }
    }
}

int main(){
    int test,no = 0; cin >> test;
    while(test--){
        int n; cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i].x >> a[i].y;
            a[i].id = i;
        }
        sort(a, a+n, &cmp_x);
        mindist = 1e20;
        Solve(0, n-1);
        cout << fixed << setprecision(10);
        cout << mindist << " " << ansa << " " << ansb << '\n';
    }
    return 0;
}
