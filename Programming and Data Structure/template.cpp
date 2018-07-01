/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x))
#define sf(n) scanf("%d",&n)
#define pf(n) printf("%d", n)
#define pfn() printf("\n")
#define pfs() printf(" ")
#define inf 1<<28;
#define M 1000000007
#define pb push_back
#define mp make_pair
#define MAX 10001
// g = __gcd(g, x);
using namespace std;

///  template <class T> inline  = > always need(inline is not must need)           T gcd ( T a, T b )  => just like functiion prototype
template <class T> inline   T gcd(T a, T b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
/// template <class T>    T function_name( T parameter_list) {  }
int main()
{
    int x,y;
    while(cin>>x>>y)
        cout<<"gcd = "<<gcd(x,y)<<endl;
    return 0;
}
