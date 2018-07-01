#include<bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAX 5

struct MAT {
    int R[MAX+1];
} M[MAX];

int N;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

bool comp(MAT A, MAT B) {
    for(int k=0; k<N; k++) {
        if(A.R[k] > B.R[k]) return true;
        if(A.R[k] < B.R[k]) return false;
    }
    return true;
}

void print(void) {
    int i, j;
    cout << "..." << endl;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) cout << M[i].R[j] << '\t';
        cout << M[i].R[j] << endl;
    }
    cout << "..." << endl;
}

void modify(MAT &A, MAT B, int a, int b) {
    for(int r=0; r<=N; r++) A.R[r] = a*B.R[r] - b*A.R[r];
}

void eliminate(void) {
    int i, g, k;
    for(i=0; i<N-1; i++) {
        if(!M[i].R[i]) {
            sort(&M[i], M+N, comp);
            assert(M[i].R[i]);
        }
        DEBUG print();
        for(k=i+1; k<N; k++) {
            g = gcd(abs(M[i].R[i]), abs(M[k].R[i]));
            modify(M[k], M[i], M[k].R[i]/g, M[i].R[i]/g);
        }
        DEBUG print();
    }
}

void reduce(void) {
    int i, g, k;
    for(i=N-1; i; i--) {
        for(k=i-1; k>=0; k--) {
            g = gcd(abs(M[i].R[i]), abs(M[k].R[i]));
            modify(M[k], M[i], M[k].R[i]/g, M[i].R[i]/g);
        }
        DEBUG print();
    }
}

void printsol(void) {
    double h, l;
    cout << "Solve for " << N << " variables:" << endl;
    for(int i=0; i<N; i++) {
        assert(M[i].R[i]);
        h = M[i].R[i];
        l = M[i].R[N];
        cout << 'x' << i+1 << " = " << l/h << endl;
    }
    cout << "..." << endl;
}

int main(void) {
    int i, j, g;
    while(cin >> N) {
        if(!N) break;
        memset(M, 0, sizeof(M));
        for(i=0; i<N; i++) {
            for(j=0; j<N; j++) cin >> M[i].R[j];
            cin >> M[i].R[j];
            for(j=g=0; j<=N; j++) g = gcd(abs(M[i].R[j]), g);
            for(j=0; j<=N; j++) M[i].R[j] /= g;
        }
        eliminate();
        reduce();
        printsol();
    }
    return 0;
}
