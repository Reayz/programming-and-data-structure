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
// g = __gcd(g, x);
using namespace std;

#define MAX 3000
int array[MAX][MAX];
void factorial()
{
    array[0][0] = array[1][0] = 1;
    for(int i=2; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            array[i][j] += array[i-1][j]*i;
            if(array[i][j]>9)
            {
                array[i][j+1] += array[i][j]/10;
                array[i][j]%=10;
            }
        }
    }
}
int main()
{
    factorial();
    int n;
    while(cin>>n)
    {
        cout<<n<<"!"<<endl;
        bool flag = 1;
        for(int i=MAX-1; i>=0; i--)
        {
            if(array[n][i]==0 and flag) continue;
            else flag=0;
            cout<<array[n][i];
        }
        cout<<endl;
    }
    return 0;
}
