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

#include<queue>
/// use - Binary_Heap, Dijkstra_algorithm, Prim's_algorithm etc
/// mypq.push()
/// mypq.pop()
/// mypq.top()
/// mypq.size()
/// mypq.empty()
priority_queue<int>mypq;
int main()
{
    cout<<"Pushing some random number..."<<endl;
    for(int i=1; i<6; i++)
    {
        mypq.push(i*i*i);
    }
    mypq.push(27);
    mypq.push(5);

    cout<<"Priority queue size is: "<<mypq.size()<<endl;

    while(!mypq.empty())
    {
        cout<<mypq.top()<<endl;
        mypq.pop();
    }

    cout<<"Priority queue size is: "<<mypq.size()<<endl;
    return 0;
}
