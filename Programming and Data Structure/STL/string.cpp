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
#define LL long long int
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

int main()
{
    string s, ss;
    cin>>s>>ss;
    int len=ss.size();

    /// substr
    cout<<"substr: "<<s.substr(0,len)<<endl;

    /// find
    cout<<"find: "<<s.find(ss,0)<<endl;
    return 0;
}
