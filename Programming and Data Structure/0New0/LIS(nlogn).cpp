/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int inf = 2000000000;

int n, L[MAX], I[MAX];
int Seq[MAX];  // initial Sequence
int LisSeq[MAX]; // Sequence with LIS
int LIS(){
    int i;
    I[0] = -inf;
    for(i=1;i<=n;i++) I[i] = inf;
    int Lislength = 0;
    for(i=0;i<n;i++){
        int low,high,mid;
        low = 0;
        high = Lislength;
        // Binary Search to find position of Seq[i] in L
        while(low <= high){
            mid = (low + high)/2;
            if(I[mid] < Seq[i]) low = mid + 1;
            else high = mid - 1;
        }
        I[low] = Seq[i];
        L[i] = low;
        if(Lislength < low) Lislength = low;
    }
    return Lislength;
}

void findSeq(int maxlength){
    int i,j;
    i = 0;
    // find the position of the item whose L[] is maximum
    for(j = 1;j < n; j++){
        if(L[j] > L[i]) i = j;
    }
    //data saving from right to left
    int top = L[i] - 1;
    LisSeq[top] = Seq[i];
    top--;
    for(j = i-1;j >= 0;j--){
        if(Seq[j] < Seq[i] && L[j] == L[i]-1){
            i = j;
            LisSeq[top] = Seq[i];
            top--;
        }
    }
    // Show the list
    printf("LIS is :");
    for(i = 0;i < maxlength; i++){
        printf(" %d",LisSeq[i]);
    }
    puts("");
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&Seq[i]);
    int result = LIS();
    printf("The LIS result is %d\n",result);
    findSeq(result);
    return 0;
}
