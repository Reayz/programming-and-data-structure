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

int main()
{
    ///int to string
    stringstream ss;
    int a = 1234;
    ss<<a;  /// stream in
    string s1;
    ss>>s1; /// stream out
    cout<<s1 + 'a'<<endl;

    ///string to int
    ss.clear();
    string s = "1234";
    ss<<s;
    int b;
    ss>>b;
    cout<<b + 1<<endl;

    /// char* to string
    ss.clear();
    char somechars[10] = "ruet cse";
    ss<<somechars;
    string somestrings;
    ss>>somestrings;
    cout<<somestrings<<endl;    /// string is work untill a white space

    /// string to char*
    ss.clear();
    somestrings = "ruet cse";
    ss<<somestrings;
    ss>>somechars;
    cout<<somechars<<endl;

    /// an application
    char line[1000];
    gets(line);
    stringstream sss( line ); // initialize kortesi
    int num;
    while( sss >> num )
        cout<<num<<' ';
    return 0;
}
