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

/// use - BFS, FIFO etc
/// Q.push()
/// Q.pop()
/// Q.front()
/// Q.back()
/// Q.size()
/// Q.empty()
queue<int>Q;
int main()
{
    for(int i=1; i<8; i++)
        Q.push(i*i);

    cout<<"Queue size is: "<<Q.size()<<endl;
    cout<<"Front element is: "<<Q.front()<<endl;
    cout<<"Back element is: "<<Q.back()<<endl;

    for( ;!Q.empty(); )
    {
        cout<<Q.front()<<endl;
        Q.pop();
    }

    Q.push(27);
    Q.push(17);

    cout<<"Front element is: "<<Q.front()<<endl;
    cout<<"Back element is: "<<Q.back()<<endl;

    Q.front() -= Q.back();
    Q.back() += Q.front();

    cout<<"Front element is: "<<Q.front()<<endl;
    cout<<"Back element is: "<<Q.back()<<endl;
    return 0;
}
