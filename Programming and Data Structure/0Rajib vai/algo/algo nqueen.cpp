#include<bits/stdc++.h>
using namespace std;

const int mx = 100;
int queen[mx];
int col[mx],dig1[2*mx],dig2[2*mx];
int total;

void nqueen(int now,int n)
{
    if(now == n+1)
    {
        total++;
        cout << "(row column) = " ;
        for(int i =1;i<=n;i++) cout << " (" << i << ","<<queen[i]<<")";
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i] or dig1[i+now] or dig2[n+i-now]) continue;
        queen[now] = i;
        col[i] = dig1[i+now] = dig2[n+i-now] = 1;
        nqueen(now+1,n);
        col[i] = dig1[i+now] = dig2[n+i-now] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    nqueen(1,n);
    cout << total << endl;
    return 0;
}
