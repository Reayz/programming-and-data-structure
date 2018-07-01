/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
const ll MOD = 1000000007;
const int MAX = 100005;

const int NX = 1000;
int input[ NX + 5] , n ;
void LIS_with_set()
{
    set < int > lis ;
    set < int > :: iterator  it ;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&input[i]);
        lis.insert( input[i]);
        it = lis.find( input[i]);
        it++;
        // if its not the end of lis then removing it position value for better small value on that position
        if( it != lis.end()) lis.erase(it);
        // for(it=lis.begin(); it!=lis.end(); it++) cout<<*it<<" "; cout<<endl;
    }
    cout << "LIS = " << lis.size() << endl ;
}

/*
/// if duplicate value allow(3 3 4), then use multiset instead of set
void LIS_with_set()
{
    multiset < int > lis ;
    multiset < int > :: iterator  it ;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&input[i]);
        lis.insert( input[i]);
        it = lis.upper_bound( input[i]);
        if( it != lis.end()) lis.erase(it);
    }
    cout << "LIS = " << lis.size() << endl ;
}
*/
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LIS_with_set();
    return 0;
}
