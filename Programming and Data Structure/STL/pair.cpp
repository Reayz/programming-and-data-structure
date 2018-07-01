/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x))
#define sf(n) scanf("%d",&n);
#define pf(n) printf("%d", n);
#define pfn() printf("\n")
#define inf 1<<28;
#define M 1000000007
#define pb push_back
#define mp make_pair
#define MAX 10001
// g = __gcd(g, x);
using namespace std;

#include<utility>
/// pii.first
/// pii.second
/// pii.make_pair
int main() {
    /// simple constructions
    pair< int, int > px(23, 43);
    cout << "px: (" << px.first << ", " << px.second << ")\n"<<endl;

    pair< int, int > pr = pair< int, int >(234, 534);
    cout << "pr: (" << pr.first << ", " << pr.second << ")\n"<<endl;

    pair< int, int > py;
    py.first = px.first * pr.first;
    py.second = px.second * pr.second;
    cout << "py: (" << py.first << ", " << py.second << ")\n"<<endl;


    /// bit more complex
    pair< pair< int, int >, pair< int, int > > p3;              /// Last er > > 2tar modde space rakte hobe
    p3 = pair< pair<int, int>, pair< int, int > > (px, py);
    cout << "p3: ((";
    cout << p3.first.first << ", " << p3.first.second << "), (";
    cout << p3.second.first << ", " << p3.second.second << "))\n";


    /// using make_pair()
    pair< double, pair< string, int > > p4;
    p4 = make_pair(3.14159, make_pair("pi", 5) );
    cout << "\nThis is " << p4.second.first << ", value: " << p4.first<< " precision: " << p4.second.second << " digits\n";
    return 0;
}
