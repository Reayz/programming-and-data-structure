/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define pii pair < int , int >
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define bit_cnt(mask) __builtin_popcount(mask)
using namespace std;
#define MOD 1000000007
ll bigmod(ll n, ll r)
{
    if(r==0) return 1;
    if(r==1) return n;
    if(r%2==0)
    {
        ll ret = bigmod(n, r/2);
        return ((ret%MOD) * (ret%MOD)) % MOD;
    }
    else return ((n%MOD) * (bigmod(n,r-1)%MOD)) % MOD;
}
ll modinverse(ll a){return bigmod(a,MOD-2)%MOD;}
ll lcm(ll a, ll b) {a=abs(a); b=abs(b); return (a/__gcd(a,b))*b;}
ll gcd(ll a, ll b) {a=abs(a); b=abs(b); if(!b) return a; return __gcd(b,a%b);}
#define MAX 100005
/// Knuth Morris Pratt (KMP)
/// find a string/pattern in another string/text
vector<int> prefix_function(string p){
    int m=p.size();
    vector<int>prefix(m);
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = prefix[len-1];
            }
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }
    return prefix;
}
vector<int> KMP(string t, string p){
    int n=t.size();
    int m=p.size();
    vector<int>prefix;
    prefix = prefix_function(p);
    vector<int>answer;
    int i = 0;
    int j  = 0;
    while (i < n)
    {
        if (p[j] == t[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            answer.pb(i-j);
            j = prefix[j-1];
        }
        else if (i < n and p[j] != t[i])
        {
            if (j != 0)
                j = prefix[j-1];
            else
                i++;
        }
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string t, p;    /// text and pattern
    cin>>t>>p;
    vector<int>answer;
    answer = KMP(t,p);
    for(int i=0; i<answer.size(); i++)
        cout<<answer[i]+1<<" ";     /// for 1-base indexing
    cout<<endl;
    return 0;
}
/// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
