#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x,y;
};

double mindist;

bool x_order(Point a, Point b){
    return a.x < b.x;
}

bool les(Point a, Point b){
    if(a.y < b.y) return true;
    if(a.y > b.y) return false;
    return a.x < b.x;
}

inline double Dist(Point a, Point b){
    double dist = sqrt((a.x - b.x) * (a.x - b.x) +
                       (a.y - b.y) * (a.y - b.y) + 0.0);
    return dist;
}

void Merge(Point *a, Point *aux, int lo, int mid, int hi){
    int i, j, k;
    for(k = lo;k <= hi; k++){
        aux[k] = a[k];
    }
    i = lo; j = mid + 1; k = lo;
    while(i <= mid && j <= hi){
        a[k++] = les(aux[i], aux[j]) ? aux[i++] : aux[j++];
    }
    while(i <= mid){
        a[k++] = aux[i++];
    }
}

double go(Point *p_x, Point *p_y, Point *aux, int lo, int hi){
    if(hi <= lo) return (1.0 * 1e20);
    int mid = lo + (hi - lo) / 2;
    double left = go(p_x, p_y, aux, lo, mid);
    double right = go(p_x, p_y, aux, mid + 1, hi);
    double d = min(left, right);
    Merge(p_y, aux, lo, mid, hi);

    int k = 0;
    for(int i = lo;i <= hi; i++){
        if(abs(p_x[mid].x - p_y[i].x) < d){
            aux[k++] = p_y[i];
        }
    }

    for(int i = 0;i < k; i++){
        for(int j = i + 1;j < k && (aux[j].y - aux[i].y) < d; j++){
            if(Dist(aux[i],aux[j]) < d){
                d = Dist(aux[i], aux[j]);
            }
        }
    }
    return d;
}

int main(){
    int n;
    while(scanf("%d",&n) == 1 && n){
        Point *p, *p_y, *aux, *save;
        p = new Point[n];
        save = new Point[n];
        aux = new Point[n];
        p_y = new Point[n];
        for(int i = 0;i < n; i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
            save[i] = p[i];
        }
        mindist = 1e20;
        sort(p, p + n, x_order);
        for(int i = 0;i < n; i++){
            p_y[i] = p[i];
        }
        mindist = min(mindist , go(p, p_y, aux, 0, n - 1));
        if(mindist > 10000){
            puts("INFINITY");
        }else {
            printf("%.4lf\n",mindist);
        }
    }
    return 0;
}
