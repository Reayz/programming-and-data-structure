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
#define all(v) v.begin(), v.end()
#define MAX 10001
// g = __gcd(g, x);
using namespace std;

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l > r;
  }
};
main ()
{
    priority_queue<int, vector<int>, compare > pq;

    pq.push(1);
    pq.push(16);
    pq.push(6);
    pq.push(13);
    while ( !pq.empty() )
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
