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

int main()
{
/// constructors used in the same order as described above:
    vector<int> first1;                                /// empty vector of ints
    vector<int> first2[15];                                /// 15 vector of ints
    vector<int> first3(15);                                    /// 1 vector of ints size 15

    vector<int> second (4,100);                       /// four ints with value 100

    vector<int> third (second.begin(),second.end());  /// iterating through second
    for (int i=0; i < third.size(); i++)
        cout << third[i] << " ";

    vector<int> fourth (third);                       /// a copy of third

    /// the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    cout << "\nThe contents of fifth are:";
    for (int i=0; i < fifth.size(); i++)        cout << " " << fifth[i];        cout << endl;

    return 0;
}
