#include<bits/stdc++.h>
using namespace std;

const int mx = 100005;
const int inf = (1<<28);

int BLOCK[505];
int inp[mx];

int GetId(int indx,int blocksz){
    return indx/blocksz;
}

void Init(int sz){
    for(int i=0;i<=sz;i++) BLOCK[i] = inf;
}

void Update(int val,int indx,int blocksz){
    int id = GetId(indx,blocksz);
    BLOCK[id] = min(BLOCK[id],val);
}

int Query(int L,int R,int blocksz){
    int lid = GetId(L,blocksz);
    int rid = GetId(R,blocksz);
    if(lid == rid){
        int ret = inf;
        for(int i=L;i<=R;i++) ret = min(ret,inp[i]);
        return ret;
    }
    int p1,p2,p3;
    p1 = p2 = p3 = inf;
    for(int i=L;i<(lid+1)*blocksz;i++) p1 = min(p1,inp[i]);
    for(int i=lid+1;i<rid;i++) p2 = min(p2,BLOCK[i]);
    for(int i=rid*blocksz;i<=R;i++) p3 = min(p3,inp[i]);
    return min(p1,min(p2,p3));
}

int main(){
    int n,q;
    while(scanf("%d %d",&n,&q) == 2){
        int blocksz = sqrt(n);
        Init(blocksz);
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            inp[i] = x;
            Update(x,i,blocksz);
        }
        while(q--){
            int x,y; scanf("%d %d",&x,&y);
            printf("%d\n",Query(x,y,blocksz));
        }
    }
    return 0;
}
