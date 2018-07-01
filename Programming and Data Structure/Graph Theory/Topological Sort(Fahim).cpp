/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define pi 2*acos(0.0)
#define Pi acos(-1)
#define PI 3.1415926535897932384626433832795
using namespace std;

#define M 1000000007
#define MAX 10001

template <class T> inline   T gcd(T a, T b){if(b==0) return a; return gcd(b,a%b);}
template <class T> inline   T ncr(T n, T r){return n*(n-1)/r;}

#define M 55
vector<int> ans, depends[M];
int taken[M];
/// depends[i] contains all the items that item i is depending on
/// when taken[i] = 1, that means it's already taken
void take( int p ) {
    if( !taken[ p ] ) {
        /// i am taking all the items that i should take before p
        for(int i=0; i<depends[p].size(); i++)
            take( depends[p][i] );
        ans.push_back( p ); /// now i can take it
        taken[p] = 1;
    }
}
int main()
{
    //freopen("topsort.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        depends[x].pb(y);       /// x er age y       x depended in y
    }
    for(int i=1; i<=n; i++) take(i);
    for(int i=0; i<n; i++) printf("%d ", ans[i] );
    return 0;
}
