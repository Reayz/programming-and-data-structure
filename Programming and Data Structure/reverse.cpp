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
#define MAX 10001
// g = __gcd(g, x);
using namespace std;

int main()
{
    /// string
    string s = "reayz";
        reverse(s.begin(), s.end());
    cout<<s<<endl<<endl;

    /// array
    int arr[] = {5, 9, 2, 17};
        reverse(arr, arr+4);
    for(int i=0; i<4; i++) cout<<arr[i]<<" ";
    cout<<endl<<endl;

    /// vector
    vector<int>v;
    v.push_back(7);
    v.push_back(17);
    v.push_back(27);
    v.push_back(77);
        reverse(v.begin(), v.end());
    for(int i=0; i<4; i++) cout<<v.at(i)<<" ";
    cout<<endl<<endl;

    return 0;
}
