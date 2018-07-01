/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define Pi acos(-1)
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define linf 100000000000000000
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define bit_cnt(mask) __builtin_popcount(mask)
using namespace std;
template < class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return __gcd(b,a%b);}
template < class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/__gcd(a,b))*b;}
template < class T > inline T ncr(T n, T r){return n*(n-1)/r;}
#define MOD 1000000007
#define MAX 100005

int a[4004], b[4004], c[4004], d[4004];
vector<int>v;
int BinarySearch(int x)
{
    int low=0, high=v.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]>x) high=mid-1;
        else if(v[mid]<x) low=mid+1;
        else
        {
            int cnt=0;
            for(int i=mid; i<=high; i++)
            {
                if(v[i]==x) cnt++;
                else break;
            }
            for(int i=mid-1; i>=0; i--)
            {
                if(v[i]==x) cnt++;
                else break;
            }
            return cnt;
        }
    }
    return 0;
}
int main()
{
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            v.pb(a[i]+b[j]);
    sort(all(v));
    ll cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int x = (c[i]+d[j])*(-1);
            cnt += (ll) BinarySearch(x);
        }
    cout<<cnt<<endl;
    return 0;
}

