/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30;
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define PI 3.1415926535897932384626433832795
using namespace std;

#define M 1000000007
#define MAX 10001

template <class T> inline   T gcd(T a, T b){if(b==0) return a; return gcd(b,a%b);}
template <class T> inline   T ncr(T n, T r){return n*(n-1)/r;}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cout<<"Enter array size: ";
    int n;
    cin>>n;
    int num[n+1], sum[n+1];
    sum[0]=0;
    cout<<"Enter element: ";
    for(int i=1; i<=n; i++)
    {
        cin>>num[i];
        sum[i]=sum[i-1] + num[i];
    }
    int i,j;
    while(1)
    {
        cout<<"Enter the range(i & j): ";
        cin>>i>>j;
        cout<<"Sum("<<i<<" to "<<j<<"): "<<sum[j]-sum[i-1]<<endl;
    }
    return 0;
}
