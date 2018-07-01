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

/// use - DFS, LIFO etc
/// mystack.push()
/// mystack.pop()
/// mystack.top()
/// mystack.size()
/// mystack.empty()
stack<int>myStack;
int main()
{
    for(int i=1; i<8; i++)
        myStack.push(i);

    cout<<"Stack size is: "<<myStack.size()<<endl;

    while(!myStack.empty())
    {
        cout<<myStack.top()<<endl;
        myStack.pop();
    }

    myStack.push(100);
    myStack.top() += 27;
    cout<<"Now top element is: "<<myStack.top()<<endl;

    return 0;
}
