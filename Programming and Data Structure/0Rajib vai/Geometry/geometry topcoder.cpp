#include<bits/stdc++.h>
using namespace std;

int dot(int A[],int B[],int C[]){
    int AB[2],BC[2];
    AB[0] = B[0] - A[0];
    AB[1] = B[1] - A[1];
    BC[0] = C[0] - B[0];
    BC[1] = C[1] - B[1];
    int dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}

int cross(int A[],int B[],int C[]){
    int AB[2],AC[2];
    AB[0] = B[0] - A[0];
    AB[1] = B[1] - A[1];
    AC[0] = C[0] - A[0];
    AC[1] = C[1] - A[1];
    int cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}

double distance(int A[],int B[]){
    int d1 = A[0] - B[0];
    int d2 = A[1] - B[1];
    return sqrt(d1*d1+d2*d2);
}

double linePointDist(int A[],int B[],int C[],bool isSegment){
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment){
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return abs(dist);
}

double area(int A[],int B[],int C[]){
    int d1 = A[0] * B[1] + B[0] * C[1] + C[0] * A[1];
    int d2 = A[1] * B[0] + B[1] * C[0] + C[1] * A[0];
    return abs(d1 - d2) / 2.0;
}

int main(){
    int test; cin >> test;
    while(test--){
        int A[2],B[2],C[2];
        cin >> A[0] >> A[1];
        cin >> B[0] >> B[1];
        cin >> C[0] >> C[1];
        cout << dot(A,B,C) << '\n';
        cout << cross(A,B,C) << '\n';
        cout << distance(A,B) << " " << distance(B,C) << " " << distance(C,A) << '\n';
        cout << linePointDist(A,B,C,1) << '\n';
        cout << linePointDist(A,B,C,0) << '\n';
        cout << area(A,B,C) << '\n';
    }
    return 0;
}
