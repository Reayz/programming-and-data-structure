#include<bits/stdc++.h>
using namespace std;

const int inf = 2000000000;

int n; // number of items in the sequence
int Sequence[32];
int LisSequence[32];
int L[32];
int I[32];

void takeInput(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&Sequence[i]);
}

int LisNlogK(){
    int i;

    I[0] = -inf;
    for(i=1;i<=n;i++) I[i] = inf;

    int Lislength = 0;

    for(i=0;i<n;i++){
        int low,high,mid;
        low = 0;
        high = Lislength;

        while(low <= high){
            mid = (low + high)/2;
            if(I[mid] < Sequence[i]) low = mid + 1;
            else high = mid - 1;
        }
        I[low] = Sequence[i];
        L[i] = low;
        if(Lislength < low) Lislength = low;
    }
    //for(i=0;i<n;i++) printf("%d ",L[i]); printf("\n");
    return Lislength;
}

void findSequence(int maxlength){
    int i,j;
    i = 0;
    for(j = 1;j < n; j++){
        if(L[j] > L[i]) i = j;
    }
    int top = L[i] - 1;
    LisSequence[top] = Sequence[i];
    top--;
    for(j = i-1;j >= 0;j--){
        if(Sequence[j] < Sequence[i] && L[j] == L[i]-1){
            i = j;
            LisSequence[top] = Sequence[i];
            top--;
        }
    }
    printf("LIS is :");
    for(i = 0;i < maxlength; i++){
        printf(" %d",LisSequence[i]);
    }
    puts("");
}

int main(){
    takeInput();
    int result = LisNlogK();
    printf("The LIS result is %d\n",result);
    findSequence(result);
    main();
    return 0;
}
