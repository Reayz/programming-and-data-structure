#include <stdio.h>

int inp[12345];

void Heapify(int n,int i){
    int large = i,tmp;
    int l = i + i + 1;
    int r = i + i + 2;
    if(l < n && inp[l] > inp[large]) large = l;
    if(r < n && inp[r] > inp[large]) large = r;
    if(large != i){
        tmp = inp[large];
        inp[large] = inp[i];
        inp[i] = tmp;
        Heapify(n,large);
    }
}

void HeapSort(int n){
    int i,tmp;
    for(i=n/2-1;i>=0;i--){
        Heapify(n,i);
    }
    for(i=n-1;i>=0;i--){
        tmp = inp[i];
        inp[i] = inp[0];
        inp[0] = tmp;
        Heapify(i,0);
    }
}

int main(){
    int test; scanf("%d",&test);
    while(test--){
        int n,i; scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&inp[i]);
        HeapSort(n);
        for(i=0;i<n;i++) printf("%d ",inp[i]); puts("");
    }
    return 0;
}
