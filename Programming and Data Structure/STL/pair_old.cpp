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
using namespace std;

pair<int, int>p[52];
int main()
{
    for(int i=0; i<3; i++)
        cin>>p[i].first>>p[i].second;

    p[3] = make_pair(2, 4);

    sort(p, p+3);

    for(int i=0; i<4; i++)
        cout<<p[i].first<<" "<<p[i].second<<endl;

    cout<<"vector & pair: "<<endl;
    vector< pair<int, int> >pii;
    pii.push_back( make_pair(2,3) );
    cout<<pii[0].first<<" "<<pii[0].second<<endl;

    return 0;
}
