#include <bits/stdc++.h>
using namespace std;

int n,m;
int inp[105][105];
int tree[4*105][4*105];

void build_y(int node_x,int node_y,int ly,int ry,int lx,int rx){
    if(ly == ry){
        if(lx == rx) tree[node_x][node_y] = inp[lx][ry];
        else tree[node_x][node_y] = tree[node_x * 2][node_y] + tree[node_x * 2 + 1][node_y];
        return ;
    }else{
        int mid = (ly + ry) / 2;
        build_y(node_x,node_y * 2,ly,mid,lx,rx);
        build_y(node_x,node_y * 2 + 1,mid + 1, ry,lx,rx);
        tree[node_x][node_y] = tree[node_x][node_y * 2] + tree[node_x][node_y * 2 + 1];
        return ;
    }
}

void build_x(int node,int b,int e){
    if(b != e){
        int mid = (b + e) / 2;
        build_x(node * 2, b, mid);
        build_x(node * 2 + 1,mid + 1, e);
    }
    build_y(node,1,1,m,b,e);
}

void update_y(int node_x,int node_y,int lx,int rx,int ly,int ry,int x,int y,int v){
    if(ly == ry){
        if(lx == rx) tree[node_x][node_y] = v;
        else tree[node_x][node_y] = tree[node_x*2][node_y] + tree[node_x*2+1][node_y];
    }else{
        int mid = (ly + ry) / 2;
        if(y <= mid) update_y(node_x,node_y*2,lx,rx,ly,mid,x,y,v);
        else update_y(node_x,node_y*2+1,lx,rx,mid+1,ry,x,y,v);
        tree[node_x][node_y] = tree[node_x][node_y*2] + tree[node_x][node_y*2+1];
    }
}

void update_x(int node,int b,int e,int x,int y,int v){
    if(b != e){
        int mid = (b + e) / 2;
        if(x <= mid) update_x(node*2,b,mid,x,y,v);
        else update_x(node*2+1,mid+1,e,x,y,v);
    }
    update_y(node,1,b,e,1,m,x,y,v);
}

int query_y(int node_x,int node_y,int b,int e,int ly,int ry){
    if(ly <= b && e <= ry) return tree[node_x][node_y];
    int mid = (b + e) / 2;
    if(ry <= mid) return query_y(node_x,node_y*2,b,mid,ly,ry);
    else if(mid < ly) return query_y(node_x,node_y*2+1,mid+1,e,ly,ry);
    else{
        return query_y(node_x,node_y*2,b,mid,ly,ry) +
               query_y(node_x,node_y*2+1,mid+1,e,ly,ry);
    }
}

int query_x(int node,int b,int e,int lx,int rx,int ly,int ry){
    if(lx <= b && e <= rx){
        return query_y(node,1,1,m,ly,ry);
    }else{
        int mid = (b + e) / 2;
        if(rx <= mid) return query_x(node*2,b,mid,lx,rx,ly,ry);
        else if(mid < lx) return query_x(node*2+1,mid+1,e,lx,rx,ly,ry);
        else{
            return query_x(node*2,b,mid,lx,rx,ly,ry) +
                   query_x(node*2+1,mid+1,e,lx,rx,ly,ry);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> inp[i][j];
        }
    }
    build_x(1,1,n);

    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int ty; cin >> ty;
        if(ty == 1){
            int x, y, v; cin >> x >> y >> v;
            update_x(1,1,n,x,y,v);
        }else{
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            int ans = query_x(1,1,n,x1,x2,y1,y2);
            cout << ans << '\n';
        }
    }
    return 0;
}
