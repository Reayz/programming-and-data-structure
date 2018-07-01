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

#define all(v) v.begin(), v.end()
int main()
{
    pair<int, int> p;
    p = {3, 4}; /// <- use this instend of p = make_pair(3, 4)[bad use]

    string s="REABYZ", a="AB", b="ab";
    cout<<s.find(a)<<"=a & b="<<s.find(b)<<endl;

    vector<int> v;
    v.push_back(22);
    v.push_back(7);
    v.push_back(5);
    v.push_back(17);
    v.push_back(9);

    std::vector<int>::iterator sm;

    sm = min_element( all(v) ) ;
    cout << "The smallest element in " << ( sm - v.begin() ) << " index(count from 0) \n"; ///index

    cout << "The largest element is "  << *max_element( all(v) ) << '\n'; ///max_element

    sort( all(v) );                                                                             /// must be sorted
    cout<<"binary search: "<< binary_search(v.begin(), v.end(), 17) <<endl;  /// search

    if( find(v.begin(), v.end(), 177) != v.end() )  /// not need to sort
        cout<<"Item is found!"<<endl;
    else
        cout<<"Item isn't found!"<<endl;
    return 0;
}
