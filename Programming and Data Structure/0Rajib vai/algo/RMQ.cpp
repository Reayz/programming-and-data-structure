#include<bits/stdc++.h>
using namespace std;

#define mx 1000006

int arr[mx];
int st[24][mx];

void Compute_ST(int n)
{
    for(int i=0;i<n;i++) st[0][i] = i;
    for(int k=1;(1<<k)<n;k++)
    {
        for(int i=0;i+(1<<k)<=n;i++)
        {
            int x = st[k-1][i];
            int y = st[k-1][i+(1<<k - 1)];
            st[k][i] = arr[x] <= arr[y] ? x : y;
        }
        //for(int i=0;i+(1<<k)<=n;i++) cout << st[k][i] << " ";
        //cout << endl;
    }
}

int RMQ(int i,int j)
{
    int k = log2(j-i);
    int x = st[k][i];
    int y = st[k][j-(1<<k)+1];
    return arr[x] <= arr[y] ? x : y;
}

int main()
{
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    Compute_ST(n);
    int q; cin >> q;
    while(q--)
    {
        int x,y; cin >> x >> y;
        cout << arr[RMQ(x,y)] << endl;
    }
    return 0;
}
