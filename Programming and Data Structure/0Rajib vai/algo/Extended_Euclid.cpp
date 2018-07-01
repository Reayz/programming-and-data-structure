#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<bitset>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define clr0(a) memset(a,0,sizeof(a))
#define clr1(a) memset(a,1,sizeof(a))
#define clr_1(a) memset(a,-1,sizeof(a))
#define clrI(a) memset(a,63,sizeof(a))
#define pb push_back
#define re return(0)
#define sc scanf
#define pf printf
#define pii pair<int,int>
#define pq priority_queue
#define mp make_pair
#define fs first
#define se second

#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sf(t) scanf("%f",&t)
#define sd(t) scanf("%lf",&t)
#define sci(ch) scanf("%c",&ch)
#define sii(a,b) scanf("%d%d",&a,&b)
#define sll(a,b) scanf("%I64d%I64d",&a,&b)
#define sdd(a,b) scanf("%lf%lf",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define slll(a,b,c) scanf("%I64d%I64d%I64d",&a,&b,&c)
#define sddd(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)

#define mx5 100005
#define mx6 1000006
#define mx7 10000007
#define mx8 100000008
#define mx9 1000000009
#define inf 1<<30
#define eps 1e-7
#define pi  2*acos(0.0)
#define PI  3.141592653589793
#define mod 1000000007

typedef long long LL;
typedef unsigned long long LLU;

const LL infinity=100000000000000LL;

int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

int Extended_Euclid(int A,int B,int &X,int *Y)
{
    int x,y,u,v,q,a,b,m,n,r;
    x=0;
    y=1;
    u=1;
    v=0;
    a=A;
    b=B;
    while(a!=0)
    {
        q=b/a;

        r=b%a;
        b=a;
        a=r;

        m=x-u*q;
        n=y-v*q;

        x=u;
        y=v;
        u=m;
        v=n;
    }

    *X=x;
    *Y=y;
    cout<<X<<" "<<Y<<endl;
    cout<<a<<" "<<b<<endl;
}

int main()
{
    int a,b;
    while(sii(a,b)==2){
    Extended_Euclid(a,b);
    }
    return 0;
}
